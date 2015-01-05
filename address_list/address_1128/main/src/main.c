/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：  main.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/11/15
Description：多功能通讯录主函数
Funcion List: 
             1.int create_list(LINK *head);
             1.int menu(LINK *head);
*****************************************************/

#include "../../include/myhead.h"

FILE *fp;

int main()
{
    system("clear");

    fp = fopen("information_address","rw+");

    LINK head;                  //定义头指针

    create_list(&head);         //调用create_list函数创建头结点
        
    file_to_address(&head);     //将文件内容读出
   
    menu(&head);                //调用界面函数显示界面并在界面函数里检测输入
}
