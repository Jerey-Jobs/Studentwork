#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 

#define MY_PORT 3333

int main(int argc ,char **argv)
{
 int listen_fd,accept_fd;
 struct sockaddr_in     client_addr;
 int n;
 
 if((listen_fd=socket(AF_INET,SOCK_STREAM,0))<0)
  {
        printf("Socket Error:%s\n\a",strerror(errno));
        exit(1);
  }
 
 bzero(&client_addr,sizeof(struct sockaddr_in));
 client_addr.sin_family=AF_INET;
 client_addr.sin_port=htons(MY_PORT);
 client_addr.sin_addr.s_addr=htonl(INADDR_ANY);
 n=1;
 /* �����������ֹ��,���������Եڶ��ο������������õȴ�һ��ʱ��  */
 setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&n,sizeof(int));
 if(bind(listen_fd,(struct sockaddr *)&client_addr,sizeof(client_addr))<0)
  {
        printf("Bind Error:%s\n\a",strerror(errno));
        exit(1);
  }
  listen(listen_fd,5);
  while(1)
  {
   accept_fd=accept(listen_fd,NULL,NULL);
   if((accept_fd<0)&&(errno==EINTR))
          continue;
   else if(accept_fd<0)
    {
        printf("Accept Error:%s\n\a",strerror(errno));
        continue;
    }
  if((n=fork())==0)
   {
        /* �ӽ��̴���ͻ��˵����� */
        char buffer[1024];

        close(listen_fd);
        n=read(accept_fd,buffer,1024);
        write(accept_fd,buffer,n);
        close(accept_fd);
        exit(0);
   }
   else if(n<0)
        printf("Fork Error:%s\n\a",strerror(errno));
   close(accept_fd);
  }
} 
