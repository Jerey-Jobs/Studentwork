/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：ban.c
Author：Jerey_Jobs    Version:0.1    Date:2015/1/120 
Description：服务器对发来的管理员禁言操作进行处理
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int ban(int fd,MSG buf)
{
    /*再次检查一下是否是管理员执行的操作*/
    if((my_strcmp(buf.id,"10000") != 0) || (my_strcmp(buf.password,"admin") != 0))
    {
        printf("管理员账号密码不对|%s|%s|\n",buf.id,buf.password);
        return 0;    
    }

    LINK tmp = head;
    MSG str;               //待返回消息

    int count = 0;         
    
    
    while(tmp != NULL)
    {
        printf("禁言比较|%s|%s|\n",tmp->name,str.toname);
        /*遍历链表找到需要禁言的用户*/
        if(my_strcmp(tmp->name,buf.toname) == 0)
        {   
            /*若该用户在线则发送禁言消息给他*/
        	if(tmp->state == LINE)
        	{
                str.action = BAN_OK;               //并返回禁言成功消息给管理员
                write(fd,&str,sizeof(str));
                str.action = BANED;
                write(tmp->fd,&str,sizeof(str));                              
                printf("管理员禁言%s成功\n",buf.toname);
                return 0;
        	}
        	else                                   //若不在线则返回消息告诉管理员禁言对象不在线      
        	{
                str.action = BAN_NOTLINE;                  
                write(fd,&str,sizeof(str));
                printf("管理员禁言%s 不在线 \n",buf.toname);
                return 0;
        	}
        }
    	tmp = tmp->next;
    }
 
    //若未找到用户 则告诉管理员对方不存在
    str.action = BAN_NOTEXIST;
    write(fd,&str,sizeof(str));
    printf("管理员禁言%s不存在\n",buf.toname);

    return 0;
}
