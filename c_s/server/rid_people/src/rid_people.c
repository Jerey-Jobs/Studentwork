/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：rid_people.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.22 
Description：对管理员解禁行为进行处理
Funcion List: int rid_people(int fd,MSG buf)
*****************************************************/

#include "../../include/myhead.h"

int rid_people(int fd,MSG buf)
{
    /*再次检查一下是否是管理员执行的操作*/
	if((my_strcmp(buf.id,"10000") != 0) || (my_strcmp(buf.password,"admin") != 0))
    {
        return 0;    
    }

    LINK tmp = head;
    MSG str;

    /*遍历链表找到需要解除禁言的用户*/
    while(tmp != NULL)
    {
        if(my_strcmp(tmp->name,buf.toname) == 0)
        {   
            /*若该用户在线则解除禁言 并告诉管理员解除禁言成功*/
        	if(tmp->state == LINE)
        	{
                str.action = RID_OK;
                write(fd,&str,sizeof(str));
                str.action = RIDED;
                write(tmp->fd,&str,sizeof(str));                
                printf("管理员解除禁言%s成功\n",buf.toname);
                return 0;
        	}
            /*否则告诉管理员对象不在线*/
        	else
        	{
                str.action = RID_NOTLINE;                  
                write(fd,&str,sizeof(str));
                printf("管理员解除禁言%s 不在线 \n",buf.toname);
                return 0;
        	}
        }
    	tmp = tmp->next;
    }
 
    /*若未找到 则告诉管理员对方不存在*/
    str.action = RID_NOTEXIST;
    write(fd,&str,sizeof(str));
    printf("解除禁言%s不存在\n",buf.toname);

    return 0;
}
