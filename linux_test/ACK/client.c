#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>

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

    printf("please input send string:");
    char buf[1024] = {0};
    scanf("%s",buf);

    int len = send(cs,buf,strlen(buf),0);

    memset(buf,0,sizeof(buf));

    int recvlen = recv(cs,buf,sizeof(buf)-1,0);

    if(recvlen == 0)
    {
        printf("peer part haved closed socket\n");
    }
    else if(recvlen < 0)
    {
        perror("recv error:");
    }
    else
    {
        printf("recv:%s\n",buf);
    }

    printf("press any key to exit!\n");
    getchar();
    getchar();
    close(cs);
    return 0;
}
