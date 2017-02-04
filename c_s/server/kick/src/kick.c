/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：kick.c
Author：Jerey_Jobs    Version:0.1    Date: 2015.1.20
Description：对管理员踢人进行处理
Funcion List: int kick.c
*****************************************************/
#include "../../include/myhead.h"

int kick(int fd,MSG buf)
{
    /*再次检查是否是管理员进行操作*/
	if((my_strcmp(buf.id,"10000") != 0) || (my_strcmp(buf.password,"admin") != 0))
    {
        return 0;    
    }

    LINK tmp = head;
    MSG str;              //待回复消息

    int count = 0;
    
    /*在用户信息链表中找到该用户*/
    while(tmp != NULL)
    {
    	printf("踢人~~~~%s~~~~%s~~",tmp->name,buf.toname);

        if(my_strcmp(tmp->name,buf.toname) == 0)
        {   
            /*若该用户在线 */
        	if(tmp->state == LINE)
        	{
                /*告诉管理员踢人成功*/
                str.action = KICK_OK;
                tmp->state = NOTLINE;
                write(fd,&str,sizeof(str));
                
                /*告诉该用户被踢出了*/
                str.action = KICKED;
                write(tmp->fd,&str,sizeof(str));

                printf("管理员踢出%s成功\n",buf.toname);                
                return 0;
        	}
            /*若不在线则告诉管理员对方不在线*/
        	else
        	{
                str.action = KICK_NOTLINE;                  
                write(fd,&str,sizeof(str));
                printf("管理员踢出的人%s 不在线 \n",buf.toname);
                return 0;
        	}
        }
    	tmp = tmp->next;
    }
     
    /*若未找到用户 则告诉管理员对方不存在*/
    str.action = KICK_NOTEXIST;
    write(fd,&str,sizeof(str));
    printf("管理员踢出的人%s不存在\n",buf.toname);

    return 0;
}
