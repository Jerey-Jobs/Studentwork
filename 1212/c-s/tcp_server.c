/*hahahah*/
#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h>
#include <pthread.h>

#define portnumber 3333

struct message
{
    int action;
    char name[20];
    char toname[20];
    char msg[100];
};

struct online
{
    int fd;
    char name[20];
    struct online *next;
};

struct online *head;

int creat_online()
{
    head = NULL;
}

int insert_online(struct online *new)
{
    new->next = head;
    head = new;
}

int find_fd(char *toname)
{
    struct online *tmp = head;
    while(tmp->next != NULL)
    {
        if(strcmp(tmp->name,toname) == 0)
        {
            return tmp->fd;
        }

        tmp = tmp->next;
    }
    return -1;
}

void read_message(void *arg)
{
     int fd = *((int *)arg);
     
     struct message buf;

     int count;
     int toname_fd;
     
     struct online *new = (struct online *)malloc(sizeof(struct online));
     while(1)
     {
         memset(&buf,0,sizeof(buf));

         if((count = read(fd,&buf,sizeof(buf))) != 0)
         {
             printf("get ");
             printf("action = %d  ",buf.action);
             printf("  name = %s\n",buf.name);

             if(buf.action == 1)
             {
                 new->fd = fd;
                 strcpy(new->name,buf.name);
                 insert_online(new);
                 write(fd,&buf,sizeof(buf));
             }

             if(buf.action == 2)
             {
                 toname_fd = find_fd(buf.toname);
                 
                 if(toname_fd == -1)
                 {
                     printf("there no that people!\n");
                 }
                 else
                 {
                     write(toname_fd,&buf,sizeof(buf));
                 }
             }
         }
	      
    }

}

/*
void write_message(void *arg)
{
     int fd = *((int *)arg);
     
     int count;
   //  char buffer[1024];
      
     while(1)
     {
         //pthread_mutex_lock(&mutex);
	     if((count = write(fd,&buf,strlen(buffer))) > 0)
         {
	         printf("AAA!%s\n",buffer);
             sleep(2);

         }
	 //pthread_mutex_unlock(&mutex);
    }

}
*/

int main(int argc, char *argv[]) 
{ 
	int sockfd,new_fd; 
	struct sockaddr_in server_addr; 
	struct sockaddr_in client_addr; 
	int sin_size; 
	char msg[1024]; 
	

	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{ 
		fprintf(stderr,"Socket error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 
        
	printf("socket!\n");

	bzero(&server_addr,sizeof(struct sockaddr_in)); 	
    server_addr.sin_family=AF_INET;                	
    server_addr.sin_addr.s_addr=inet_addr("192.168.1.199");  
	server_addr.sin_port=htons(portnumber);        
    
    if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 

	printf("bind!\n");

	if(listen(sockfd,5)==-1) 
	{ 
		fprintf(stderr,"Listen error:%s\n\a",strerror(errno)); 
		exit(1); 
	}

	printf("listen!\n");

	int count;
	pthread_t id1;
	pthread_t id2;

	while(1) 
	{ 
	
        sin_size=sizeof(struct sockaddr_in); 
		if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))==-1) 
		{ 
			fprintf(stderr,"Accept error:%s\n\a",strerror(errno)); 
			exit(1); 
		} 
      
       
		printf("accpet!\n");
		fprintf(stderr,"Server get connection from %s\n",inet_ntoa(client_addr.sin_addr));
        pthread_create(&id1,NULL,(void *)read_message,(void *)&new_fd);
	//	pthread_create(&id2,NULL,(void *)write_message,(void *)&new_fd);
		
	} 

	close(sockfd); 
	exit(0); 
} 
