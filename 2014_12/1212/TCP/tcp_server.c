#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

#include <pthread.h>

#define portnumber 3333
	
struct sockaddr_in server_addr; 
struct sockaddr_in client_addr; 
int sockfd;

void *sever_accept()
{
	int new_fd; 
	int sin_size; 
    char buffer[1024];
    int count;
    
    pthread_t id;

    sin_size=sizeof(struct sockaddr_in); 
		
    if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))==-1) 
	{ 
		fprintf(stderr,"Accept error:%s\n\a",strerror(errno)); 
		exit(1); 
    } 

	printf("accpet!\n");

    pthread_create(&id,NULL,(void *)sever_accept,NULL);

	fprintf(stderr,"Server get connection from %s\n",inet_ntoa(client_addr.sin_addr)); 
		
    memset(buffer,0,sizeof(buffer));
		
    while((count = read(new_fd,buffer,sizeof(buffer))) > 0) 
	{ 
        buffer[count] = '\0';

		printf("read a msg : %s\n",buffer);
    

        char getmsg[] = "I have got your msg!";

        if(write(new_fd,getmsg,strlen(getmsg)) != 0)
        {
            printf("send msg ok!\n");
        }

    }

	close(new_fd); 

    pthread_join(id,NULL);
}

int main(int argc, char *argv[]) 
{ 
	int new_fd; 
	int sin_size; 
    char buffer[100];
    int count;

    pthread_t id;

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

    sever_accept();

	close(sockfd); 
	exit(0); 
} 
