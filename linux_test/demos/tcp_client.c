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
      
     while(1)
     {
         //pthread_mutex_lock(&mutex);
	 if((count = read(fd,buffer,sizeof(buffer))) > 0)
         {
             buffer[count] = '\0';
	     printf("buffer = %s\n",buffer);
	//     memset(buffer,0,sizeof(buffer));
         }
	 //pthread_mutex_unlock(&mutex);
    }

}

int main(int argc, char *argv[]) 
{ 
	int sockfd; 
	char buffer[1024]; 
	struct sockaddr_in server_addr; 
	struct hostent *host; 
	int nbytes; 

        /* 使用hostname查询host 名字 */
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

	/* 客户程序开始建立 sockfd描述符 */ 
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) // AF_INET:Internet;SOCK_STREAM:TCP
	{ 
		fprintf(stderr,"Socket Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

	/* 客户程序填充服务端的资料 */ 
	bzero(&server_addr,sizeof(server_addr)); // 初始化,置0
	server_addr.sin_family=AF_INET;          // IPV4
	server_addr.sin_port=htons(portnumber);  // (将本机器上的short数据转化为网络上的short数据)端口号
	//server_addr.sin_addr=*((struct in_addr *)host->h_addr); // IP地址
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);  //用于绑定到一个固定IP,inet_addr用于把数字加格式的ip转化为整形ip
	
	/* 客户程序发起连接请求 */ 
	if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Connect Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 
        pthread_t id;
	pthread_create(&id,NULL,(void *)read_message,(void *)&sockfd);

        while(1)
	{
        /* 连接成功了 */ 
	   scanf("%s",buffer);
	   if((nbytes=write(sockfd,buffer,1024))==-1) 
	   { 
		fprintf(stderr,"Read Error:%s\n",strerror(errno)); 
		exit(1); 
	   }
	}

	/* 结束通讯 */ 
	close(sockfd); 
	exit(0); 
} 
