/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int logoff(int fd,MSG buf)
{
	LINK tmp = head;

	while(tmp != NULL)
	{	
        if(my_strcmp(tmp->name,buf.name) == 0)
        {
            tmp->state = NOTLINE;
        }

        tmp = tmp->next;
	}


	MSG str;

    str.action = LOGOFF_OK;

    write(fd,&str,sizeof(str));

    return 0;
}
