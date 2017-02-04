#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>

void *recvThread(void *param)
{
    char buf[1024] = {0};
    int *cs = (int *)param;
    while(1)
    {
        memset(buf,0,sizeof(buf));
        int recvlen = recv(*cs,buf,sizeof(-1),0);
        
        if(recvlen <= 0)
            break;
        else
            printf("recv:%s\n",buf);
    }
}


int main(int argc,char **argv)
{
    int cs;
    struct sockaddr_in serv,cli;
    
    cs = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    if(cs < 0)
    {
	      perror("call socket failure");
      	return -1;
    }
    
    serv.sin_family = AF_INET;
    serv.sin_port = htons(5001);
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(cs,(struct sockaddr *)&serv,sizeof(serv)) < 0)
    {
	      perror("connect server failure:");
      	return -1;
    }

   int threadid;
   pthread_create(&threadid,0,recvThread,&cs);
   
   char buf[1024];
   while(1)
   {
       memset(buf,0,sizeof(buf));
       scanf("%s",buf);
       if(send(cs,buf,strlen(buf),0) <= 0)
       {
           break;
       }
   }

    printf("press any key to exit!\n");
    getchar();
    getchar();
    close(cs);
    return 0;
}
