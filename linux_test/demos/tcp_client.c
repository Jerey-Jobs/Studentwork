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

        /* ʹ��hostname��ѯhost ���� */
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

	/* �ͻ�����ʼ���� sockfd������ */ 
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) // AF_INET:Internet;SOCK_STREAM:TCP
	{ 
		fprintf(stderr,"Socket Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

	/* �ͻ�����������˵����� */ 
	bzero(&server_addr,sizeof(server_addr)); // ��ʼ��,��0
	server_addr.sin_family=AF_INET;          // IPV4
	server_addr.sin_port=htons(portnumber);  // (���������ϵ�short����ת��Ϊ�����ϵ�short����)�˿ں�
	//server_addr.sin_addr=*((struct in_addr *)host->h_addr); // IP��ַ
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);  //���ڰ󶨵�һ���̶�IP,inet_addr���ڰ����ּӸ�ʽ��ipת��Ϊ����ip
	
	/* �ͻ��������������� */ 
	if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Connect Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 
        pthread_t id;
	pthread_create(&id,NULL,(void *)read_message,(void *)&sockfd);

        while(1)
	{
        /* ���ӳɹ��� */ 
	   scanf("%s",buffer);
	   if((nbytes=write(sockfd,buffer,1024))==-1) 
	   { 
		fprintf(stderr,"Read Error:%s\n",strerror(errno)); 
		exit(1); 
	   }
	}

	/* ����ͨѶ */ 
	close(sockfd); 
	exit(0); 
} 
