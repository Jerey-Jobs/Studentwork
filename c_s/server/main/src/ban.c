/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int ban(int fd,MSG buf)
{

    if((my_strcmp(buf.id,"10000") != 0) || (my_strcmp(buf.password,"admin") != 0))
    {
        printf("管理员账号密码不对|%s|%s|\n",buf.id,buf.password);
        return 0;    
    }

    LINK tmp = head;
    MSG str;

    int count = 0;
    
    while(tmp != NULL)
    {
        printf("禁言比较|%s|%s|\n",tmp->name,str.toname);

        if(my_strcmp(tmp->name,buf.toname) == 0)
        {   
        	if(tmp->state == LINE)
        	{
                str.action = BAN_OK;
                write(fd,&str,sizeof(str));
                str.action = BANED;
                write(tmp->fd,&str,sizeof(str));                
                printf("管理员禁言%s成功\n",buf.toname);
                return 0;
        	}
        	else
        	{
                str.action = BAN_NOTLINE;                  
                write(fd,&str,sizeof(str));
                printf("管理员禁言%s 不在线 \n",buf.toname);
                return 0;
        	}
        }
    	tmp = tmp->next;
    }
 
    str.action = BAN_NOTEXIST;
    write(fd,&str,sizeof(str));
    printf("管理员禁言%s不存在\n",buf.toname);

    return 0;
}
