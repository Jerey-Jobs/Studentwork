/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

extern FILE *fp;

int write_to_file(LINK *head)    
{
    LINK tmp = (*head)->next;
    fseek(fp,0,SEEK_SET);
 
    char str[1024];

    while(tmp != NULL)
    {
        memset(str,0,sizeof(str));
    
        sprintf(str,"%d|%s|%s|%s|%s\0",tmp->num,tmp->name,tmp->phonenum,tmp->address,tmp->homephone);
    
        fwrite(str,1,strlen(str),fp);
        fwrite("\n",1,1,fp);
        tmp = tmp->next;
    }     

    return 333;
}
