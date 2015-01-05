/*******************************：**********************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：menu.c
Author：Jerey_Jobs    Version:0.1    Date: 
Description：主界面函数
Funcion List:   int check_putin(LINK *head);
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:       void menu(MSG msg) 
Description:    主菜单界面函数 
Calls:          int check_putin()
Called By:      main
Input:          LIeNK *had  链表头结点
Return:         no
*************************************************/ 
void menu_admin() 
{

    system("clear");      //清屏

    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*                哟哟哟哟 搭讪房1.0           *\033[0m\n");
    printf("\t\t\033[47;31m*                                -Jerey Jobs  *\033[0m\n");
    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*   1.查看在线人员(show)   2.悄悄话(chat)     *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*   3.广播(broad)          4.表情(hi)         *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*   5.修改密码(cpwd)       6.修改昵称(rname)  *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");
    printf("\t\t\033[47;31m*   7.登出(logoff)         8.退出(exit)       *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");       
    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\t\t\033[47;31m*当前用户为管理员享有特权功能                 *\033[0m\n");
    printf("\t\t\033[47;31m*                                             *\033[0m\n");       
    printf("\t\t\033[47;31m*  踢人(kick)     禁言(ban)     解禁(rid)     *\033[0m\n");       
    printf("\t\t\033[47;31m***********************************************\033[0m\n");
    printf("\t\t\033[47;31m*任何帮助请：help                             *\033[0m\n");

}
