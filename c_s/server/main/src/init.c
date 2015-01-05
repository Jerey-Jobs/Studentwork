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
extern char **result;

int init()
{
	head = NULL;

    LINK tmp = head;

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
                                      //解析出ID 并赋值给新节点

        strcpy(newnode->name,result[i * ncolumn]);
        
        strcpy(newnode->id,result[i * ncolumn + 1]);

        strcpy(newnode->password,result[i * ncolumn + 2]);
    
        newnode->state = NOTLINE;

        newnode->next = head;
        head = newnode;
    }
    
    uhead = NULL;

    UNREAD *temp = uhead;

    UNREAD *new;

    char **unread;

    rc = sqlite3_get_table(db,"select * from left_message",&unread,&nrow,&ncolumn,&errmsg);
    
    for(i = 1; i <= nrow; i++)
    {
        new = (UNREAD *)malloc(sizeof(UNREAD));

        strcpy(new->name,unread[i * ncolumn]);

        strcpy(new->toname,unread[i * ncolumn + 1]);
        
        strcpy(new->msg,unread[i * ncolumn + 2]);
       
        new->next = uhead;

        uhead = new;
    }

    return 0;
}
