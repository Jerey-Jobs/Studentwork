/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int rname()
{
	if(msg.state != LINE)
	{
		printf("对不起，您还未登陆");
		getchar();
		return NOTLINE;
	}

	msg.action = RNAME;

	printf("\t\t\033[47;31m 请输入新昵称：\033[0m\n");
	scanf("%s",msg.name);

	if(write(sockfd,&msg,sizeof(msg)) == -1) 
	{
        fprintf(stderr,"rname write Error:%s\n",strerror(errno)); 
    }
    
    printf("rname ok\n");
    
    printf("\t\t\033[47;31m 按任意键返回！\033[0m\n");
    getchar();
    getchar();
    return 0;
}
