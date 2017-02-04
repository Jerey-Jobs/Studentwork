#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <sys/socket.h>

#define PORT 81
#define BACKLOG 10
#define LENGTH 1024

char httpweb[] = {
	"HTTP/1.0.200OK\r\n"
    "Date:Mon,24,NOV2005 10:26:00 GMT\r\n"
    "Server:microHttp/1.0 ZHIYUAN Electronics CO.,LTD\r\n"
    "Accept_Ranges:bytes\r\n"
    "Connection : keep-close\r\n"
    "Content-Type : text/html\r\n"
    "\r\n"
};

char web[] = {
	"<HTML>\r\n"
	"<HEAD>\r\n"
	"<TITLE> 208120632演示</TITLE>\r\n"
	"<BODY><alink=green bgColor=#f1fdd link=red\r\n"
	"vLink=#321afd>\r\n"
	"<H1>hello</H1>\r\n"
	"<UL>\r\n"
	 "<LI><A HREF=\"http://www.zyinside.com\">guangzhou</A>\r\n"
        "</BODY>"
        "<HTML>\r\n"
};

char httpgif[] = {
	"HTTP/1.0 200K\r\n"
    "Date:Mon,24 Nov2005 10:26:00 GMT\r\n"
    "Server:microHttp/1.0 ZHIYUAN Electronics CO.,LTD\r\n"
    "Accept_Ranges:bytes\r\n"
    "Connection:Keep-Close\r\n"
    "Content-Type:image/bmp\r\n"
    "\r\n"
};

int main()
{
    int sockfd;
    int nsockfd;
    int i;
    int num;
    int flag = 1;
    int sin_size;
    char revbuf[LENGTH];
    struct sockaddr_in addr_local;
    struct sockaddr_in addr_remote;

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
    	printf("socket ERror\n");
    	return 0;
    }
    else
    {
    	printf("socket ok!!!\n");
    }

    addr_local.sin_family = AF_INET;
    addr_local.sin_port = htons(PORT);
    addr_local.sin_addr.s_addr = INADDR_ANY;

    bzero(&(addr_local.sin_zero),8);

    if(bind(sockfd,(struct sockaddr*)&addr_local,sizeof(struct sockaddr))==-1)
    {
        printf("error:failed to bind port %d \n", PORT);
        return 0;
    }
    else
    {
        printf("ok:bind the port %d succesdsfully \n", PORT);
    }

    if(listen(sockfd,BACKLOG) == -1)
    {
        printf("error:failed to listen port %d \n", PORT);
        return 0;
    }
    else
    {
        printf("ok:listening the port %dsuccesdsfully \n", PORT);
    }

    while(1)
    {
        sin_size = sizeof(struct sockaddr_in);

        if((nsockfd = accept(sockfd,(struct sockaddr*)&addr_remote,&sin_size)) == -1)
        {
            printf("error:obtain new socket descriptor error\n");
            continue;
        }
        else
        {
            printf("ok:sever has got connect from %s\n",inet_ntoa(addr_remote.sin_addr));
        }


        num = recv(nsockfd,revbuf,LENGTH,0);

        if(!fork())
        {
            printf("ok http:web is servering\n");

            if(revbuf[5] == ' ')
            {
            	send(nsockfd,httpweb,sizeof(httpweb),0);
            	send(nsockfd,web,sizeof(web),0);
            } 
            else if(revbuf[5]== '1')
            {
            	send(nsockfd,httpgif,sizeof(httpgif),0);
            }
         }

        close(nsockfd);
        while(waitpid(-1, NULL,WNOHANG) > 0);

    }
   
	return 0;
}









