/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：init.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.20 
Description：服务器初始化函数
Funcion List: int init();
*****************************************************/

#include "../../include/myhead.h"

extern sqlite3 *db;
extern char *errmsg;
extern char **result;

int init()
{
    /*创建用户信息链表*/
	head = NULL;

    LINK tmp = head;

    /*将数据库数据读出*/
    int rc;
    int i;
    int nrow;              //数据库行数
    int ncolumn;           //数据库列数
 
    LINK newnode;          

    rc = sqlite3_get_table(db,"select * from cilent",&result,&nrow,&ncolumn,&errmsg);
    
    /*将数据库的数据行每列挨个赋值给节点并插入链表*/
    for(i = 1; i <= nrow; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
                                    
        strcpy(newnode->name,result[i * ncolumn]);
        
        strcpy(newnode->id,result[i * ncolumn + 1]);

        strcpy(newnode->password,result[i * ncolumn + 2]);
    
        newnode->state = NOTLINE;
        
        /*插入链表*/
        newnode->next = head;
        head = newnode;
    }
    
    /*创建离线消息链表*/
    uhead = NULL;

    UNREAD *temp = uhead;
    
    /*创建离线消息新结点*/
    UNREAD *new;

    char **unread;
    
    /*将数据库消息读出并插入链表*/
    rc = sqlite3_get_table(db,"select * from left_message",&unread,&nrow,&ncolumn,&errmsg);
    
    for(i = 1; i <= nrow; i++)
    {
        new = (UNREAD *)malloc(sizeof(UNREAD));

        strcpy(new->name,unread[i * ncolumn]);

        strcpy(new->toname,unread[i * ncolumn + 1]);
        
        strcpy(new->msg,unread[i * ncolumn + 2]);
       
        /*头插法插入链表*/
        new->next = uhead;
        uhead = new;
    }

    return 0;
}
