/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：send_file.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.22 
Description：发送文件函数
Funcion List: int send_file(int fd,MSG buf)
*****************************************************/
#include "../../include/myhead.h"

int send_file(int fd,MSG buf)
{
    printf("(((((开始发送文件函数开始))))))\n");
	MSG str = buf;

	LINK tmp = head;

	int count = 0;

	str.action = SEND_FILE;
 
    /*遍历链表找到需要接收的用户*/
    while(tmp != NULL)
    {
        if(my_strcmp(tmp->name,str.toname) == 0)
        {   
            /*若对方在线 则发送文件内容给他*/
        	if(tmp->state == LINE)
        	{
        		write(tmp->fd,&str,sizeof(str));
            	printf("%s ->>send%s  内容 %s\n",str.name,str.toname,str.msg); 
          	    count = LINE;
        	}
        	else
        	{
        		count = NOTLINE;
        	}
        }
    	tmp = tmp->next;
    }
    
    /*同时告诉用户发送文件成功*/
    if(count == LINE)
    {
        str.action = SEND_OK;
    }

    /*count还是 0 则不存在用户*/
    else if(count == 0)
    {
    	str.action = SEND_NOT_EXIST;
    }

    /*告诉用户对方不在线*/
    else if(count == NOTLINE)
    {
    	str.action = SEND_NOTLINE;
    }
    
    write(fd,&str,sizeof(str));

    return 0;
}

