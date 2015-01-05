/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/
#include "../../include/myhead.h"

int check_hi(char *src)
{
    int flag = 0;
    if(my_strcmp(src,"doubt") == 0)
    {
    	return HI_1;
    }
    
    if(my_strcmp(src,"embrass") == 0)
    {
    	return HI_2;
    }

    if(my_strcmp(src,"happy") == 0)
    {
    	return HI_3;
    }

    if(my_strcmp(src,"touching") == 0)
    {
    	return HI_4;
    }

    if(my_strcmp(src,"xiuse") == 0)
    {
    	return HI_5;
    }

    if(my_strcmp(src,"shenmegui") == 0)
    {
    	return HI_6;
    }
}



int hi_people(int fd,MSG buf)
{
    MSG str;

	LINK tmp = head;

    str.action = check_hi(buf.msg);

    strcpy(str.name,buf.name);

    printf("hi_people :::: %s %d\n",buf.msg,check_hi(buf.msg));

    while(tmp != NULL)
    {
        if(tmp->state == LINE && tmp->fd != fd)
        {
        	write(tmp->fd,&str,sizeof(str));
        }
 
    	tmp = tmp->next;
    }
    
    str.action = HI_OK;
    
    write(fd,&str,sizeof(str));

    return 0;
}
