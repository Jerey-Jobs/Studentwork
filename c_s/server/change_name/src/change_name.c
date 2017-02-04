/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：change_name.c
Author：Jerey_Jobs    Version:0.1    Date:2015、1、20 
Description：客户端改名，服务器对应操作
Funcion List: 
*****************************************************/
#include "../../include/myhead.h"
extern sqlite3 *db;
extern char *errmsg;

int change_name(int fd,MSG buf)
{
	LINK tmp = head;

    /*先找到客户端对应的节点 改变节点的名字*/
	while(tmp != NULL)
	{	
        if(tmp->fd == fd)
        {
          	strcpy(tmp->name,buf.name);        
        }

        tmp = tmp->next;
	}

    /*再对数据库中的该用户的信息进行更新名字 */
    char sql_str[100];

    memset(sql_str,0,sizeof(sql_str));

    sprintf(sql_str,"update cilent set name = '%s' where id = '%s'",buf.name,buf.id);
 
    sqlite3_exec(db,sql_str,NULL,NULL,&errmsg);    //写入操作
    
    printf("修改名称成功。。%s",sql_str);

    /*告诉客户端改名成功*/
    MSG str;

    str.action = RNAME_OK;

    write(fd,&str,sizeof(str));

    return 0;
}
