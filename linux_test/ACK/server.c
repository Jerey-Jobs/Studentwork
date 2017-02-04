#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


void recv_thread(int *cs);

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
    
    char buf[1024] = {0};
    int len = recv(cs, buf, sizeof(buf), 0);
    if(len < 0)
    {
        perror("recv error");    
    }
    else if(len == 0)
    {
        printf("socket %d is end!\n",cs);    
    }
    else
    {
        printf("%s\n",buf);
        send(cs,"ACK",3,0);
    }
    printf("anykey to exit");
    getchar();
    close(cs);
    
}



