#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<ctype.h>

/* 宏定义端口号 */
#define portnumber 8000

#define MAX 80




struct message
{
    int action;
    char id[20];
    char name[20];
    char password[20];
    char toname[20];
    char msg[100];
    int state;
};


typedef struct message MSG;


MSG buffer;

void read_message(void *arg)
{ 
    int fd = (int)arg;

    MSG buf = buffer;

    printf("get! readmessage\n");
    int count;
 //   MSG buf;
    
   // if((count = read(fd,&buf,sizeof(buf))) != 0)
  //  {
        printf("get!\n");

        printf("get ");

        printf("action = %d  ",buf.action);
        printf(" id = %s",buf.id);
        printf("  name = %s",buf.name);
        printf("  password = %s",buf.password);
        printf("  toname =%s",buf.toname);
        printf("  msg = %s",buf.msg);
        printf("  state = %d",buf.state);

     
    
     /*  switch(buf.action)
        {
        	case LOGIN:
            case REGISTER:
        	case CHAT:
        	case BROADCAST:
        	case CHANGE_PASSWD:
        	case LOG_OUT:
        	case CHANGE_NAME://printf("CHANGE_NAME\n");
            default: break;
        }
     */
  //  }

    printf("read end !!!!!!!\n");    
}



int main(void)
{
	int  lfd;
	int cfd;
	int sfd;
	int rdy;

	struct sockaddr_in sin;
	struct sockaddr_in cin;

	int client[FD_SETSIZE];  /* 客户端连接的套接字描述符数组 */

	int maxi;
	int maxfd;                        /* 最大连接数 */

	fd_set rset;
	fd_set allset;

	socklen_t addr_len;         /* 地址结构长度 */

	int i;
	int n = 1;
	int len;
	int opt = 1;   /* 套接字选项 */

	char addr_p[20];

	/* 对server_addr_in  结构进行赋值  */
	bzero(&sin,sizeof(struct sockaddr_in));   /* 先清零 */
	sin.sin_family=AF_INET;                 //
	sin.sin_addr.s_addr=htonl(INADDR_ANY);  //表示接受任何ip地址   将ip地址转换成网络字节序
	sin.sin_port=htons(portnumber);         //将端口号转换成网络字节序

	/* 调用socket函数创建一个TCP协议套接口 */
	if((lfd=socket(AF_INET,SOCK_STREAM,0))==-1) // AF_INET:IPV4;SOCK_STREAM:TCP
	{
		fprintf(stderr,"Socket error:%s\n\a",strerror(errno));
		exit(1);
	}
    printf("socket!\n");

	/*设置套接字选项 使用默认选项*/
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	/* 调用bind函数 将serer_addr结构绑定到sockfd上  */
	if(bind(lfd,(struct sockaddr *)(&sin),sizeof(struct sockaddr))==-1)
	{
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
		exit(1);
	}
    printf("bind!\n");

	/* 开始监听端口   等待客户的请求 */
	if(listen(lfd,20)==-1)
	{
		fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
		exit(1);
	}
    printf("listen!\n");
	printf("Accepting connections .......\n");

	maxfd = lfd;                                /*对最大文件描述符进行初始化*/
	maxi = -1;

	/*初始化客户端连接描述符集合*/
	for(i = 0;i < FD_SETSIZE;i++)
	{
        client[i] = -1;
	}

	FD_ZERO(&allset);                     /* 清空文件描述符集合 */
	FD_SET(lfd,&allset);                    /* 将监听字设置在集合内 */


	/* 开始服务程序的死循环 */
	while(1)
	{
		rset = allset;
        printf("selecting!\n");
		/*得到当前可以读的文件描述符数*/
		rdy = select(maxfd + 1, &rset, NULL, NULL, NULL);

		printf("selected!\n");
		if(FD_ISSET(lfd, &rset))
		{

			addr_len = sizeof(sin);
            printf("accepting!\n");
			/* 接受客户端的请求 */
			if((cfd=accept(lfd,(struct sockaddr *)(&cin),&addr_len))==-1)
			{
				fprintf(stderr,"Accept error:%s\n\a",strerror(errno));
				exit(1);
			}
			printf("accepted!\n");


             		 /*查找一个空闲位置*/
			for(i = 0; i<FD_SETSIZE; i++)
			{       //printf("%d\t",client[i]);
				if(client[i] <= 0)
				{
					client[i] = cfd;   /* 将处理该客户端的连接套接字设置到该位置 */
					break;
				}
			}

		/* 太多的客户端连接   服务器拒绝俄请求  跳出循环 */
			if(i == FD_SETSIZE)
			{
				printf("too many clients");
				exit(1);
			}

			FD_SET(cfd, &allset);     /* 设置连接集合 */

			if(cfd > maxfd)                  /* 新的连接描述符 */
			{
				maxfd = cfd;
			}

			if(i > maxi)
			{
				maxi = i;
			}

			if(--rdy <= 0)                /* 减少一个连接描述符 */
			{
			continue;	
			}

		}

		/* 对每一个连接描述符做处理 */
		for(i = 0;i< FD_SETSIZE;i++)
		{
			if((sfd = client[i]) < 0)
			{
				continue;
			}

			if(FD_ISSET(sfd, &rset))
			{
				printf("reading!\n");
				n = read(sfd,&buffer,sizeof(buffer));
				printf("read!\n");
				if(n == 0)
				{
					printf("the other side has been closed. \n");
					fflush(stdout);                                    /* 刷新 输出终端 */
					close(sfd);

					FD_CLR(sfd, &allset);                        /*清空连接描述符数组*/
					client[i] = -1;
				}

				else
				{
					/* 将客户端地址转换成字符串 */
					inet_ntop(AF_INET, &cin.sin_addr, addr_p, sizeof(addr_p));
					addr_p[strlen(addr_p)] = '\0';

					/*打印客户端地址 和 端口号*/
					printf("Client Ip is %s, port is %d\n",addr_p,ntohs(cin.sin_port));

			//		read_message(buffer);

				    pthread_t id;

                    pthread_create(&id,NULL,(void *)read_message,(void *)&sfd);   

                 //   memset(&buffer,0,sizeof(buffer));
					/* 写函数出错 */
					if(n == 1)
					{
						exit(1);
					}
				}

				/*如果没有可以读的套接字   退出循环*/
				if(--rdy <= 0)
				{
					break;
				}


			}
		}

	}

	close(lfd);       /* 关闭链接套接字 */
	return 0;
}
