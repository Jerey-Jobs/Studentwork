/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

sqlite3 *db = NULL;
char *errmsg = NULL;
char **result = NULL;   

struct message buffer;


void *read_message(int fd)
{ 
    MSG buf = buffer;

        printf("read message get ");

        printf(" action = %d  ",buf.action);
        printf(" id = %s",buf.id);
        printf("  name = %s",buf.name);
        printf("  password = %s",buf.password);
        printf("  toname =%s",buf.toname);
        printf("  msg = %s",buf.msg);
        printf("  state = %d\n",buf.state);

        switch(buf.action)
        {
        	case SHOW:show_people(fd,buf);break;
        	case LOG:login(fd,buf);break;
            case REGIST:regist(fd,buf);break;
        	case CHAT:chat(fd,buf);break;
        	case BROAD:broad(fd,buf);break;
        	case CPWD:change_password(fd,buf);break;
        	case LOGOFF:logoff(fd,buf);break;
        	case RNAME:change_name(fd,buf);break;
    
        	case BAN:ban(fd,buf);break;
        	case KICK:kick(fd,buf);break;
        	case RID_PEOPLE:rid_people(fd,buf);break;
        	case HI:hi_people(fd,buf);break;
            default: break;
        }

    printf("\nread message end !!!!!!!\n");    
}

int main()
{                    
	int sockfd;             //socket链接描述符
	int new_fd;             //accept返回新描述符号
	int num_fd;             //请求的连接符个数

	int tmp_cilent;         //客户端临时处理描述符

	struct sockaddr_in sin;
	struct sockaddr_in cin;

	int client[FD_SETSIZE];  /* 客户端连接的套接字描述符数组 */

	int maxi;
	int maxfd;                /* 最大连接数 */

	fd_set allset;
	fd_set tmp_set;

	socklen_t addr_len;       /* 地址结构长度 */

	int i;
	int n;
	int len;
	int opt = 1;   /* 套接字选项 */

	char addr_p[20];

	int rc;

    rc = sqlite3_open("people.db",&db);

    init();
	/* 对server_addr_in  结构进行赋值  */
	bzero(&sin,sizeof(struct sockaddr_in)); //清零
	sin.sin_family=AF_INET;                 //IPv4
	sin.sin_addr.s_addr=htonl(INADDR_ANY);  //表示接受任何ip地址   将ip地址转换成网络字节序
	sin.sin_port=htons(portnumber);         //将端口号转换成网络字节序

	/* 调用socket函数创建一个TCP协议套接口 */
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) // AF_INET:IPV4;SOCK_STREAM:TCP
	{
		fprintf(stderr,"Socket error:%s\n\a",strerror(errno));
		exit(1);
	}
    printf("socket!\n");

	/*设置套接字选项 使用默认选项*/
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	/* 调用bind函数 将serer_addr结构绑定到sockfd上  */
	if(bind(sockfd,(struct sockaddr *)(&sin),sizeof(struct sockaddr))==-1)
	{
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno));
		exit(1);
	}
    printf("bind!\n");

	/* 开始监听端口   等待客户的请求 */
	if(listen(sockfd,MAX)==-1)
	{
		fprintf(stderr,"Listen error:%s\n\a",strerror(errno));
		exit(1);
	}
    printf("listen!\n");
	printf("Accepting connections .......\n");

	maxfd = sockfd;                          /*对最大文件描述符进行初始化*/
	maxi = -1;                                  

	/*初始化客户端连接描述符集合*/
	for(i = 0;i < FD_SETSIZE;i++)
	{
        client[i] = -1;
	}

	FD_ZERO(&allset);                        /* 清空文件描述符集合 */
	FD_SET(sockfd,&allset);                  /* 将监听字设置在集合内 */

	/* 开始服务程序的死循环 */
	while(1)
	{
		tmp_set = allset;


        printf("正在select 。。。。\n");
		/*得到当前可以读的文件描述符数*/
		num_fd = select(maxfd + 1, &tmp_set, NULL, NULL, NULL);

		printf("select到了 下一步是\n");

		if(FD_ISSET(sockfd, &tmp_set))
		{

			addr_len = sizeof(sin);
            printf("正在接收客户端请求：\n");

			/* 接受客户端的请求 */
			if((new_fd=accept(sockfd,(struct sockaddr *)(&cin),&addr_len))==-1)
			{
				fprintf(stderr,"Accept error:%s\n\a",strerror(errno));
				exit(1);
			}
			printf("接收到了 下一步是\n");

            printf("%d\n",__LINE__);
            /*查找一个空闲位置*/
			for(i = 0; i < FD_SETSIZE; i++)
			{       //printf("%d\t",client[i]);
				if(client[i] <= 0)
				{
					client[i] = new_fd;   /* 将处理该客户端的连接套接字设置到该位置 */
					printf("170 cha ru OK!\n");
                    break;
				}
			}
            
	     	/* 太多的客户端连接   服务器拒绝俄请求  跳出循环 */
			if(i == FD_SETSIZE)
			{
				printf("too many clients");
				exit(1);
			}

			FD_SET(new_fd, &allset);     /* 设置连接集合 */

			if(new_fd > maxfd)                  /* 新的连接描述符 */
			{
				maxfd = new_fd;
			}

			if(i > maxi)
			{
				maxi = i;
			}

			if(--num_fd <= 0)                /* 减少一个连接描述符 */
			{
				continue;
			}

		}   
		/* 对每一个连接描述符做处理 */
		for(i = 0; i < FD_SETSIZE; i++)
		{
			if((tmp_cilent = client[i]) < 0)
			{
				continue;
			}
 //  printf("%d\n",__LINE__);         
            if(FD_ISSET(tmp_cilent, &tmp_set))
            {
   				n = read(tmp_cilent,&buffer,sizeof(buffer));
				printf("read!\n");
				if(n == 0)
				{
					printf("the other side has been closed. \n");
					fflush(stdout);                                    /* 刷新 输出终端 */
					close(tmp_cilent);

					LINK tmp_c = head;

					while(tmp_c != NULL)
					{
                        if(tmp_c->fd == tmp_cilent)
                        {
                        	tmp_c->state = NOTLINE;
                        }

                        tmp_c = tmp_c->next;
					}

					FD_CLR(tmp_cilent, &allset);                        /*清空连接描述符数组*/
					client[i] = -1;
				}

				else
				{
					/* 将客户端地址转换成字符串 */
					inet_ntop(AF_INET, &cin.sin_addr, addr_p, sizeof(addr_p));
					addr_p[strlen(addr_p)] = '\0';

					/*打印客户端地址 和 端口号*/
					printf("Client Ip is %s, port is %d\n",addr_p,ntohs(cin.sin_port));

				    pthread_t id;
                    
                    read_message(tmp_cilent);
       
					if(n == 1)
					{
						exit(1);
					}
				}

            }
		}

	}

	close(sockfd);       /* 关闭链接套接字 */

    return 0;
}
