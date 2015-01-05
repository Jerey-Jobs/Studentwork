/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

extern FILE *fp;

int file_to_address(LINK *head)
{
    LINK tmp = (*head);
    
    char r_buf[MAX];
    char *p;
 
    LINK newnode;
    
    fseek(fp,0,SEEK_SET);

    while(fgets(r_buf,MAX,fp) != NULL)
    {
        if(strlen(r_buf) != 1)
        {

            newnode = (LINK )malloc(sizeof(NODE));
       
            p = strtok(r_buf,"|");

            newnode->num = atoi(p);

            strcpy(newnode->name,strtok(NULL,"|"));
            strcpy(newnode->phonenum,strtok(NULL,"|"));
            strcpy(newnode->address,strtok(NULL,"|"));
            strcpy(newnode->homephone,strtok(NULL,"|"));

            while(tmp->next != NULL)
            {
                tmp = tmp->next;
            }

            tmp->next = newnode;
            newnode->next = NULL;
        
            memset(r_buf,0,MAX);

        }
    }
    
    return 0;
}
