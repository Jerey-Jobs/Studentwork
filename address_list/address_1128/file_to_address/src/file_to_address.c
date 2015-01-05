/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：file_to_address.c
Author：Jerey_Jobs    Version:0.1    Date:2014.11.23 
Description：将文件内容解析出来并写入通讯录
Funcion List: NO
*****************************************************/

#include "../../include/myhead.h"

extern FILE *fp;

int file_to_address(LINK *head)
{
    LINK tmp = (*head);
    
    char r_buf[MAX];                 //读取文件存放缓冲区
    char *p;
 
    LINK newnode;
    
    fseek(fp,0,SEEK_SET);

    /*每次读取文件一行 直到无数据可读*/
    while(fgets(r_buf,MAX,fp) != NULL)
    {
        /*若该行不是只有一个换行符，则解析该行*/
        if(strlen(r_buf) != 1)
        {

            /*创建节点将解析出的数据插进链表*/
            newnode = (LINK )malloc(sizeof(NODE));
       
            p = strtok(r_buf,"|");            //取出第一个|前面的字符串

            newnode->num = atoi(p);           //将ID解析出并赋值给新节点

            strcpy(newnode->name,strtok(NULL,"|"));       //同样赋值用户名字
            strcpy(newnode->phonenum,strtok(NULL,"|"));   //赋值用户手机号
            strcpy(newnode->address,strtok(NULL,"|"));    //赋值用户地址
            strcpy(newnode->homephone,strtok(NULL,"|"));  //赋值用户家庭电话

            /*尾插法插入新用户*/
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
