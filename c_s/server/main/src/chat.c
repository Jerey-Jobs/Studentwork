/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int chat(int fd,MSG buf)
{
	MSG str = buf;

	LINK tmp = head;

	int count = 0;

    while(tmp != NULL)
    {
        printf("比较|%s|%s|\n",tmp->name,str.toname);
        if(my_strcmp(tmp->name,str.toname) == 0)
        {   
        	if(tmp->state == LINE)
        	{
        		write(tmp->fd,&str,sizeof(str));
            	printf("%s ->>聊天成功%s  内容 %s\n",str.name,str.toname,str.msg); 
          	    count = LINE;
        	}
        	else
        	{
        		count = NOTLINE;
        	}
        }
    	tmp = tmp->next;
    }
    
    if(count == LINE)
    {
        str.action = CHAT_OK;
    }
    else if(count == 0)
    {
    	str.action = CHAT_NOT_EXIST;
    }
    else if(count == NOTLINE)
    {
    	str.action = CHAT_NOTLINE;
    }
    
    write(fd,&str,sizeof(str));

    return 0;
}
