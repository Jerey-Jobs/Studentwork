#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

#define portnumber 3333

struct message
{
    int action;
    char name[20];
    char password[20];
    char toname[20];
    char msg[100];
};

void read_message(void *arg)
{
     int fd = *((int *)arg);
     
     int count;
     char buffer[1024];
     struct message buf;
      
     while(1)
     {
         memset(&buf,0,sizeof(buf));
	     if((count = read(fd,&buf,sizeof(buf))) > 0)
         {
             if(buf.action == 1)
             {
                 printf("\n%s log ok !\n",buf.name);
             }
             if(buf.action == 2)
             {
                 printf("%s send msg : %s\n",buf.name,buf.msg);
             }
             
         }
    }

}

int main(int argc, char *argv[]) 
{ 
	int sockfd; 
	char buffer[1024]; 
	struct sockaddr_in server_addr; 
	struct hostent *host; 
	int nbytes; 

   
	if(argc!=2) 
	{ 
		fprintf(stderr,"Usage:%s hostname \a\n",argv[0]); 
		exit(1); 
	} 

	if((host=gethostbyname(argv[1]))==NULL) 
	{ 
		fprintf(stderr,"Gethostname error\n"); 
		exit(1); 
	} 


	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{ 
		fprintf(stderr,"Socket Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

	bzero(&server_addr,sizeof(server_addr)); 	
    server_addr.sin_family=AF_INET;     
    server_addr.sin_port=htons(portnumber);  
		
    server_addr.sin_addr.s_addr=inet_addr(argv[1]); 

	if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Connect Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 
        pthread_t id;
	pthread_create(&id,NULL,(void *)read_message,(void *)&sockfd);

    struct message msg;
    char cmd[10];
    char name[10];

    while(1)
	{
        memset(&msg,0,sizeof(msg));
        printf("please input cmd :");
        scanf("%s",cmd);

        if(strcmp(cmd,"log") == 0)
        {
            printf("input name : ");
	        scanf("%s",msg.name);
            msg.action = -100;
            strcpy(name,msg.name);

	        if((nbytes=write(sockfd,&msg,sizeof(msg)))==-1) 
	        { 
	            fprintf(stderr,"write Error:%s\n",strerror(errno)); 
            }
        }

        if(strcmp(cmd,"chat") == 0)
        {
            printf("input to name : ");
            scanf("%s",msg.toname);
            printf("input msg: ");
            scanf("%s",msg.msg);
            msg.action = 2;
            strcpy(msg.name,name);
	        if((nbytes=write(sockfd,&msg,sizeof(msg)))==-1) 
	        { 
	            fprintf(stderr,"Read Error:%s\n",strerror(errno)); 
	            exit(1); 
	        }
        }
	}

	close(sockfd); 
	exit(0); 
} 
