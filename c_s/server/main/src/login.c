/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int check_people(char *id,char *password)
{
	LINK tmp = head;

	while(tmp != NULL)
	{
		if(my_strcmp(tmp->id,id) == 0)
		{
			if(my_strcmp(tmp->password,password) == 0)
			{
			    return YES;
			}
			else
			{
				return PASSWORD_ERROR;
			}
		}

		tmp = tmp->next;
	}

	return NOT_EXIST;

}

int login(int fd,MSG buf)
{
	MSG msg = buf;
	MSG str;

	LINK temp = head;

	int ret = check_people(msg.id,msg.password);

	if(ret == YES)
	{
        while(temp != NULL)
        {
		    if(my_strcmp(temp->id,msg.id) == 0)
		    {
		    	temp->state = LINE;
                temp->fd = fd;

		    	printf("客户端上线成功。。\n");

                str.action = LOG_OK;
                strcpy(str.name,temp->name);

                write(fd,&str,sizeof(str));
		    	
		    	break;
		    }

        	temp = temp->next;
        }
	}
	else if(ret == PASSWORD_ERROR)
	{
        str.action = PASSWORD_ERROR;
        printf("客户密码错误。。\n");
        write(fd,&str,sizeof(str));      
	}
	else if(ret == NOT_EXIST)
	{
        printf("客户不存在。。\n");
        str.action = NOT_EXIST;
        write(fd,&str,sizeof(str));
	}

    temp = head;

	while(temp != NULL)
    {
    	printf("####、id %s  name %s  state %d   ####\n",temp->id,temp->name,temp->state);

    	temp = temp->next;
    }
	 

    return 0;
}
