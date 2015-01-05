/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int kick(int fd,MSG buf)
{
	if((my_strcmp(buf.name,"10000") != 0) || (my_strcmp(buf.password,"admin") != 0))
    {
        return 0;    
    }

    LINK tmp = head;
    MSG str;

    int count = 0;
    
    while(tmp != NULL)
    {
    	printf("踢人~~~~%s~~~~%s~~",tmp->name,buf.toname);

        if(my_strcmp(tmp->name,buf.toname) == 0)
        {   
        	if(tmp->state == LINE)
        	{
                str.action = KICK_OK;
                tmp->state = NOTLINE;
                write(fd,&str,sizeof(str));
                
                str.action = KICKED;
                write(tmp->fd,&str,sizeof(str));

                printf("管理员踢出%s成功\n",buf.toname);                
                return 0;
        	}
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
 
    str.action = KICK_NOTEXIST;
    write(fd,&str,sizeof(str));
    printf("管理员踢出的人%s不存在\n",buf.toname);

    return 0;
}
