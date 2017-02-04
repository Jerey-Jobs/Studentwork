#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8802
#define LENGTH 256

int main(int argc,char *argv[])
{
    int sockfd;
    int num;

    char revbuf[LENGTH];
    struct sockaddr_in remote_addr;

    if(argc != 2)
    {
    	printf("usage : client host ip (./192.168.1.92\n");
    	return 0;
    }

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
    	printf("ERROR:fail to obtain socket descriptor\n");
    	return 0;
    }


    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(PORT);
    inet_pton(AF_INET,argv[1],&remote_addr.sin_addr);
    bzero(&(remote_addr.sin_zero),8);

    if(connect(sockfd,(struct sockaddr*)&remote_addr,sizeof(struct sockaddr)) == -1)
    {
    	printf("ERROR fail to connet\n");
    	return 0;
    }
    else
    {
    	printf("OK:have connet to the %s\n", argv[1]);
    }

    while(strcmp(revbuf,"exit") != 0)
    {
    	bzero(revbuf,LENGTH);
    	num = read(sockfd,revbuf,LENGTH,0);
 		
 		switch(num)
 		{
 			case -1:
 				printf("ERROR : recive string ERROR\n");
 				close(sockfd);
 				return -1;
 			case 0:
 			    printf("SERVER has been closed\n");
 				close(sockfd);
 				return 0;
 			default: 
 			 	printf("OK: recived %d bytes\n", num);
 			 	break;
 		}

 		revbuf[num] = '\0';
 		printf("OK: Receive string : %s\n", revbuf);
    }

    close(sockfd);

	return 0;
}

