/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：show_people.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.22 
Description：显示当前在线用户
Funcion List: 
               int show_people(int fd,MSG buf)
*****************************************************/

#include "../../include/myhead.h"

int show_people(int fd,MSG buf)
{
	LINK tmp = head;
    MSG str;
    
    /*遍历用户信息链表将在线人员信息发送给当前用户*/
    while(tmp != NULL)
    {
    	memset(&str,0,sizeof(str));
        str.action = SHOW_BACK;

        if(tmp->state == LINE)
        {
            sprintf(str.toname,"[%10s]",tmp->name);
           // strcpy(str.toname,tmp->name);
            usleep(1000);
            write(fd,&str,sizeof(str));             
        }
    

    	tmp = tmp->next;
    }
    
    tmp = head;

    while(tmp != NULL)
    {
        memset(&str,0,sizeof(str));
        str.action = SHOW_BACK;

        if(tmp->state != LINE)
        {
            sprintf(str.toname,"%10s",tmp->name);
            usleep(1000);
            write(fd,&str,sizeof(str));             
        }
    
        tmp = tmp->next;
    }

    
    return 0;
}
