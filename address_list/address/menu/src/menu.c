/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：menu.c
Author：Jerey_Jobs    Version:0.1    Date: 
Description：主界面函数
Funcion List:   int check_putin(LINK *head);
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:       void menu(LINK *head) 
Description:    主菜单界面函数 
Calls:          int check_putin(LINK *head)
Called By:      main
Input:          LINK *head  链表头结点
Return:         no
*************************************************/ 
void menu(LINK *head) 
{

    system("clear");      //清屏
 
    /*打印出主界面并提示输入的选项*/
    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*                多功能通讯录1.0              *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*                                -Jerey Jobs  *\033[0m\n");
    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*   1.增加联系人              2.显示联系人    *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*   3.查找联系人              4.删除联系人    *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\n");
    printf("\n");
    printf("\t\t\033[47;31mADD/DISPLAY/SEARCH/DELETE/QUIT \033[0m\n");

    check_putin(head);  //调用check_putin检测输入的命令
}
