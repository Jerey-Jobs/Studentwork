/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：write_to_db.c
Author：Jerey_Jobs    Version:0.1    Date:2014.11.23 
Description：将通讯录的数据写入数据库中
Funcion List: NO
*****************************************************/

#include "../../include/myhead.h"

extern sqlite3 *db;
extern char *errmsg;

int write_to_db(LINK *head)    
{
    LINK tmp = (*head)->next;
 
    char str[1024];
    int rc;
   // char *err;

    /*写入前先清空数据库*/
    rc = sqlite3_exec(db,"delete from people",NULL,NULL,&errmsg);

    if(rc)
    {
        printf("insert ERROR!\n");
        printf("rc = %d\n",rc);
    }

    /*遍历链表，并将每个节点的数据写入数据库*/
    while(tmp != NULL)
    {
        memset(str,0,sizeof(str));
    
        sprintf(str,"insert into people values(%d,'%s','%s','%s','%s')",tmp->num,tmp->name,tmp->phonenum,tmp->address,tmp->homephone);
    
        printf("str:%s\n",str);
        
        rc = sqlite3_exec(db,str,NULL,NULL,&errmsg);    //写入操作

        if(rc)
        {
            printf("insert ERROR!\n");
            printf("rc = %d\n",rc);
        }

        tmp = tmp->next;
    }     

    return SUCCESS;
}
