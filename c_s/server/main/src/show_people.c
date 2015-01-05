/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int show_people(int fd,char buf)
{
	LINK tmp = head;
    MSG str;
    
    while(tmp != NULL)
    {
    	memset(&str,0,sizeof(str));

        if(tmp->state == LINE)
        {
            str.action = SHOW_BACK;
            strcpy(str.toname,tmp->name);

            printf("发送在线人成功。。%s\n",tmp->name );
            write(fd,&str,sizeof(str));             
        }

    	tmp = tmp->next;
    }
    return 0;
}
