/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int chat()
{
    if(msg.state == CHAT_BAN)
    {
        printf("您已被禁言 无法发言!!\n");
        printf("\t\t\033[47;31m 按任意键返回！\033[0m\n");
        getchar();
        return CHAT_BAN;
    }

	msg.action = CHAT;
    
    printf("悄悄话对象：");
    scanf("%s",msg.toname);

    printf("对话内容：");
    scanf("%s",msg.msg);

    if(write(sockfd,&msg,sizeof(msg)) == -1) 
	{
        fprintf(stderr,"regist write Error:%s\n",strerror(errno)); 
    }
    
    printf("chat ok\n");

    printf("\t\t\033[47;31m 按任意键返回！\033[0m\n");
    getchar();
    getchar();
    

    return 0;
}
