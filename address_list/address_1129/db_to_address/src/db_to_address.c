/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   db_to_file.c
Author：Jerey_Jobs    Version:0.1    Date: 2014.11.23
Description： 将数据库数据读取出并初始化系统
Funcion List: NO
*****************************************************/

#include "../../include/myhead.h"

extern sqlite3 *db;
extern char *errmsg;
extern char **result;

int db_to_address(LINK *head)
{
    LINK tmp = (*head);
    
    int rc;
    int i;
    int nrow;              //数据库行数
    int ncolumn;           //数据库列数
 
    LINK newnode;          

    rc = sqlite3_get_table(db,"select * from people",&result,&nrow,&ncolumn,&errmsg);
    
    /*将数据库的数据行每列挨个赋值给节点并插入链表*/
    for(i = 1; i <= nrow; i++)
    {
        newnode = (LINK )malloc(sizeof(NODE));
       
        newnode->num = atoi(result[i * ncolumn]);           //解析出ID 并赋值给新节点

        strcpy(newnode->name,result[i * ncolumn + 1]);
        
        strcpy(newnode->phonenum,result[i * ncolumn + 2]);
        
        strcpy(newnode->address,result[i * ncolumn + 3]);
            
        strcpy(newnode->homephone,result[i * ncolumn + 4]);

        /*尾插法插入新节点*/
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = newnode;
        newnode->next = NULL;
        
    }
    
    return 0;
}
