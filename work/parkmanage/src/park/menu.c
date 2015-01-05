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
void menu() 
{

    system("clear");      //清屏
 
    /*打印出主界面并提示输入的选项*/
    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*                停车场管理系统1.0            *\033[0m\n");
    printf("\t\t\033[47;31m*                                -Jerey Jobs  *\033[0m\n");
    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*         1.   我想停车                       *\033[0m\n");
    printf("\t\t\033[47;31m*         2.   我想取车                       *\033[0m\n");
    printf("\t\t\033[47;31m*         3.   查看停车厂当前情况             *\033[0m\n");
    printf("\t\t\033[47;31m*         4.   离开                           *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\n");
    printf("\n");
    printf("\t\t\033[47;31m1/2/3/4: \033[0m\n");

    check_putin();  //调用check_putin检测输入的命令
}
