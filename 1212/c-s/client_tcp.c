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

struct msg
{
    char name[20];
    char passwrd;
    int act;
};


void *readmsg(void *arg)
{
    char r_buffer[1024];
    int sockfd = (int)arg;
    while(read(sockfd,r_buffer,1024) > 0)
    {
        printf("get msg : %s\n",r_buffer);
        memset(r_buffer,0,sizeof(buffer));
    }

}

int main(int argc, char *argv[]) 
{ 
	int sockfd; 
	char buffer[1024]; 
	struct sockaddr_in server_addr; 
	struct hostent *host; 
	int nbytes; 

    pthread_t id;

	if(argc!=2) 
	{ 
		fprintf(stderr,"Usage:%s hostname \a\n",argv[0]); 
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

    pthread_create(&id,NULL,(void *)readmsg,(void *)&sockfd);

    struct msg newmsg; //= (struct msg *)malloc(sizeof(struct msg));
    
    strcpy(newmsg.name,"zhangsan");
    strcpy(newmsg.passwrd,"123456");
    newmsg.act = 1;

    while(1)
    {
       // scanf("%s",buffer);

        fprintf(buffer,"%s|%s|%d",newmsg.name,newmsg.passwrd,newmsg.act);

	    if((nbytes=write(sockfd,buffer,1024)) == -1) 
	    { 
		    fprintf(stderr,"Read Error:%s\n",strerror(errno)); 
		    exit(1); 
        }

        printf("send msg %s\n",buffer);
        memset(buffer,0,sizeof(buffer)); 
    }

	close(sockfd); 
	exit(0); 
} 
