/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

extern sqlite3 *db;
extern char *errmsg;

int change_password(int fd,MSG buf)
{
	LINK tmp = head;

	while(tmp != NULL)
	{	
        if(tmp->fd == fd)
        {
          	strcpy(tmp->password,buf.password);        
        }

        tmp = tmp->next;
	}

    char sql_str[100];

    memset(sql_str,0,sizeof(sql_str));

    sprintf(sql_str,"update cilent set password = '%s' where id = '%s'",buf.password,buf.id);

    printf("修改密码成功。。%s",sql_str);

    sqlite3_exec(db,sql_str,NULL,NULL,&errmsg);    //写入操作

    MSG str;

    str.action = CPWD_OK;

    write(fd,&str,sizeof(str));

    return 0;
}
