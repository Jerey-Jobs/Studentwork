/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   check_putin.c
Author：Jerey_Jobs    Version:0.1    Date: 
Description：检测用户输入，并调用该功能的函数
Funcion List: int check_putin(LINK *head)
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:       int check_putin(LINK *head)
Description:    检测用户输入的指令，并执行该功能函数
Calls:      my_add(head);
            my_display(head);
            my_delete(head);
            my_search(head);
            menu(head);
Called By:  menu(LINK *head)    
Input:      LINK *head    链表头指针
Return:     NO    
*************************************************/ 
int check_putin(LINK *head)
{
    char check[MAX];
    
    setbuf(stdin,NULL);                        //清空输入缓冲

    printf("\t\t\033[47;31mplease input conmand:\033[0m   ");

    gets(check);                               //读入输入的命令

    if(my_strcmp(check,"ADD") == 0)            //若输入的为ADD 则调用my_add增加一个联系人
    {
        my_add(head);
    }

    else if(my_strcmp(check,"DISPLAY") == 0)   //若输入为DISPLAY 调用my_display函数
    {
        my_display(head);
    }

    else if(my_strcmp(check,"DELETE") == 0)    //若输入为DELETE 调用my_delete函数
    {
        my_delete(head);
    }

    else if(my_strcmp(check,"SEARCH") == 0)    //若输入为SEARCH 调用my_search函数 
    {
        my_search(head);
    }
    
    else if(my_strcmp(check,"QUIT") == 0)      //若输入为QUIT 程序退出
    {
        system("clear");
        printf("\n");
        printf("\t\t\tTHANKS FOR USEING!\n");
        getchar();
        exit(1);
    }

    /*若错误输入 则继续调用menu函数 提示错误并重新输入*/
    else
    {
        printf("\t\t\033[47;31m输入错误，请重新输入!\033[0m");

  //      getchar();
        scanf("%*[^\n]");
        system("clear");
        
        menu(head);
    }

    return SUCCESS;

}
