/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name： create_list.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/11/15
Description： 创建表头
Funcion List: no
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:   void create_list(LINK *head)
Description:创建链表头  
Calls:      no
Called By:  main
Input:      LINK *head    
Return:     no
*************************************************/ 
void create_list(LINK *head)
{
    *head = (LINK)malloc(sizeof(NODE));   //开辟头结点

    if(*head == NULL)
    {
        printf("create_list malloc error!\n");

        exit(FAIL);
    }

    (*head)->next = NULL;
    (*head)->num = -1111;                 //初始化头结点
}
