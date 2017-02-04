/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：log.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.18 
Description： 用户登录函数
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int cilent_log()
{
    char passwd[20];            //存放密码
    int i;

	msg.action = LOG;           //用户动作为登录

	printf("\t\t\t\tID : ");
	scanf("%s",msg.id);
	printf("\t\t\t\t密 码 ：");
	getchar();

    char tmp_c;
    /*用不回显方式输入密码 输入一个字符打印一个 * 号*/
    for(i = 0; i < 20; i++)
    {
        tmp_c = my_getch();
        
        passwd[i] = tmp_c;
        printf("*");
        if(tmp_c == '\r')
        {
        	passwd[i] = '\0';
        	break;
        }
    }
    printf("\n");

    strcpy(msg.password,passwd);
    
    /*判断当前用户是否是管理员 若是将用户权利置1 进入管理员模式*/
    if(my_strcmp(msg.id,"10000") == 0)
    {
        if(my_strcmp(passwd,"admin") == 0)
        {
            strcpy(msg.name,"admin");
            power = 1;
        }
    }

    /*将该聊天消息写入聊天记录文件*/
	if(write(sockfd,&msg,sizeof(msg))==-1) 
	{ 
        fprintf(stderr,"log write Error:%s\n",strerror(errno)); 
    }
    
    usleep(500000);         //延迟半秒 让提示信息打出。、。

    return 0;
}
