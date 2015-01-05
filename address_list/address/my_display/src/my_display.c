/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name： my_display.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/11/15
Description： 显示数据函数
Funcion List:  int menu(LINK *head)
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
 Function:       int my_display(LINK *head)
 Description:    遍历该链表并输出所有数据
 Calls:          int menu(LINK *head)
 Called By:      int check_putin(LINK *head)
 Input:          LINK *head
 Return:         no
*************************************************/ 
void my_display(LINK *head)
{
    system("clear");                   //显示前先清屏

    if((*head)->next == NULL)          //若无数据则显示无数据       
    {
        printf("no data !\n");
    }

    LINK tmp = (*head)->next;

    /*遍历链表并输出*/
    while(tmp != NULL)
    {
        printf("\t\t\033[47;31mID          :   %d\033[0m\n",tmp->num);
        printf("\t\t\033[47;31mname        :   %s\033[0m\n",tmp->name);
        printf("\t\t\033[47;31mphonenumber :   %s\033[0m\n",tmp->phonenum);
        printf("\t\t\033[47;31maddress     :   %s\033[0m\n",tmp->address);
        printf("\t\t\033[47;31mhomephone   :   %s\033[0m\n",tmp->homephone);
        printf("\n");

        tmp = tmp->next;

    }

    printf("\n");
        
    printf("\t\t\033[47;31m按任意键返回主页!\033[0m\n");

    scanf("%*[^\n]");          //进入主菜单界面前清空行缓冲

    menu(head);
 
}
