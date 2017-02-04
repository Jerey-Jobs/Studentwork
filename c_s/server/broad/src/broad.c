/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：broad.c
Author：Jerey_Jobs    Version:0.1    Date:2015/1/20 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int broad(int fd,MSG buf)
{
	MSG str = buf;

	LINK tmp = head;

    while(tmp != NULL)
    {
        if(tmp->state == LINE)
        {
        	write(tmp->fd,&str,sizeof(str));
            printf("%s->>广播 内容 %s\n",str.name,str.msg); 
        }
 
    	tmp = tmp->next;
    }
    
    str.action = BROAD_OK;
    
    write(fd,&str,sizeof(str));

    return 0;
}



