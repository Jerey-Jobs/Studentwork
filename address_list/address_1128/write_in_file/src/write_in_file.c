/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：    write_in_file.c
Author：Jerey_Jobs    Version:0.1    Date:2013.11.23 
Description：将通讯录的数据写入文件
Funcion List: NO
*****************************************************/

#include "../../include/myhead.h"

extern FILE *fp;

int write_to_file(LINK *head)    
{
    LINK tmp = (*head)->next;
    fseek(fp,0,SEEK_SET);
 
    char str[1024];

    /*遍历链表并将每个节点的数据写入文件的一行*/
    while(tmp != NULL)
    {
        memset(str,0,sizeof(str));
    
        sprintf(str,"%d|%s|%s|%s|%s\0",tmp->num,tmp->name,tmp->phonenum,tmp->address,tmp->homephone);
    
        fwrite(str,1,strlen(str),fp);          //将整个字符串写入文件
        fwrite("\n",1,1,fp);                   //换行
        tmp = tmp->next;
    }     

    return SUCCESS;
}
