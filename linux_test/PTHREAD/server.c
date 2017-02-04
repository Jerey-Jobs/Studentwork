#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


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

int main(int argc,char **argv[])
{
    int ls;
    struct sockaddr_in serv,cli;
    
    ls = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(ls < 0)
    {
        perror("call socket failure");
        return -1;
    }
    
    serv.sin_family = AF_INET;
    serv.sin_port = htons(5001);
    serv.sin_addr.s_addr = INADDR_ANY;
    bind(ls,(struct sockaddr *)&serv, sizeof(serv));
    listen(ls,5);
    
    int clelen = sizeof(cli);
    
    int cs = accept(ls,(struct sockaddr *)&cli, &clelen);
    if(cs < 0)
    {
        perror("call accept failure");
        return -1;
    }
    
    printf("hava a client connet, the client il address : %s \n",inet_ntoa(cli.sin_addr));
    
    
    int threadid;
    pthread_create(&threadid,0,recvThread,&cs);
    
    char buf[1024] = {0};
    while(1)
    {
        memset(buf,0,sizeof(buf));
        scanf("%s",buf);
        if(send(cs,buf,strlen(buf),0) <= 0)
        {
            break;
        }
    }
    printf("anykey to exit");
    getchar();
    close(cs);
    
}





