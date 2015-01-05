#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

#define portnumber 3333

void read_message(void *arg)
{
     int fd = *((int *)arg);
     
     int count;
     char buffer[1024];

     while((count = read(fd,buffer,sizeof(buffer))) > 0)
     {
         buffer[count] = '\0';
	 printf("buffer = %s\n",buffer);
	 memset(buffer,0,sizeof(buffer));
     }
}

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

	server_addr.sin_addr.s_addr=inet_addr("192.168.1.1"); 
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
	pthread_t id;

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
		
        pthread_create(&id,NULL,(void *)read_message,(void *)&new_fd);
		
	} 

	close(sockfd); 
	exit(0); 
} 
