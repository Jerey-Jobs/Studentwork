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
    serv.sin_port = htons(5005);
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(cs,(struct sockaddr *)&serv,sizeof(serv)) < 0)
    {
        perror("connect server failure:");
        return -1;
    }

    printf("please input send name:");
    char buf[1024] = {0};
    scanf("%s",buf);

    FILE *fp = fopen(buf,"rb");

    if(fp != NULL)
    {
        int len = send(cs,buf,strlen(buf),0);
        memset(buf,0,sizeof(buf));

        recv(cs,buf,sizeof(buf)-1,0);

        if(strcmp(buf,"ACK") == 0)
        {
            while(!feof(fp))
            {
                if(feof(fp)) break;
                memset(buf,0,sizeof(buf));
                fread(buf,sizeof(buf) - 1, 1, fp);
                send(cs,buf,strlen(buf),0);

                memset(buf,0,sizeof(buf));
                recv(cs,buf,sizeof(buf)-1,0);
                if(strcmp(buf,"ACK") == 0)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }

            strcpy(buf,"!@#321#@!");
            send(cs,buf,strlen(buf),0);
            recv(cs,buf,sizeof(buf)-1,0);


        }
    }

    printf("press any key to exit!\n");
    getchar();
    close(cs);
    return 0;
}
