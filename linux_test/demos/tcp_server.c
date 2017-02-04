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

char buffer[1024] = "no message!";

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void read_message(void *arg)
{
     int fd = *((int *)arg);
     
     int count;
   //  char buffer[1024];
      
     while(1)
     {
         //pthread_mutex_lock(&mutex);
	 if((count = read(fd,buffer,sizeof(buffer))) > 0)
         {
             buffer[count] = '\0';
	     printf("buffer = %s\n",buffer);
//	     memset(buffer,0,sizeof(buffer));
         }
	 //pthread_mutex_unlock(&mutex);
    }

}

void write_message(void *arg)
{
     int fd = *((int *)arg);
     
     int count;
   //  char buffer[1024];
      
     while(1)
     {
         //pthread_mutex_lock(&mutex);
	 if((count = write(fd,buffer,sizeof(buffer))) > 0)
         {
	   printf("AAA!\n");
	   sleep(2);
         }
	 //pthread_mutex_unlock(&mutex);
    }

}


int main(int argc, char *argv[]) 
{ 
	int sockfd,new_fd; 
	struct sockaddr_in server_addr; 
	struct sockaddr_in client_addr; 
	int sin_size; 
	char msg[1024]; 
	

	/* �������˿�ʼ����sockfd������ */ 
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) // AF_INET:IPV4;SOCK_STREAM:TCP
	{ 
		fprintf(stderr,"Socket error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 
        
	printf("socket!\n");
	/* ����������� sockaddr�ṹ */ 
	bzero(&server_addr,sizeof(struct sockaddr_in)); // ��ʼ��,��0
	server_addr.sin_family=AF_INET;                 // Internet
	//server_addr.sin_addr.s_addr=htonl(INADDR_ANY);  // (���������ϵ�long����ת��Ϊ�����ϵ�long����)���κ�����ͨ��  //INADDR_ANY ��ʾ���Խ�������IP��ַ�����ݣ����󶨵����е�IP
	 server_addr.sin_addr.s_addr=inet_addr("192.168.1.1");  //���ڰ󶨵�һ���̶�IP,inet_addr���ڰ����ּӸ�ʽ��ipת��Ϊ����ip
	server_addr.sin_port=htons(portnumber);         // (���������ϵ�short����ת��Ϊ�����ϵ�short����)�˿ں�
	
	/* ����sockfd��������IP��ַ */ 
	if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 

	printf("bind!\n");

	/* �����������ӵ����ͻ����� */ 
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
		/* ����������,ֱ���ͻ����������� */ 
		sin_size=sizeof(struct sockaddr_in); 
		if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))==-1) 
		{ 
			fprintf(stderr,"Accept error:%s\n\a",strerror(errno)); 
			exit(1); 
		} 
		printf("accpet!\n");
		fprintf(stderr,"Server get connection from %s\n",inet_ntoa(client_addr.sin_addr)); // �������ַת����.�ַ���
		
		pthread_create(&id,NULL,(void *)read_message,(void *)&new_fd);
		pthread_create(&id,NULL,(void *)write_message,(void *)&new_fd);
		
	} 

	/* ����ͨѶ */ 
	close(sockfd); 
	exit(0); 
} 
