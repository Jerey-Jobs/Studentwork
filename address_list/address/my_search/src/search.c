/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name： search.c
Author：Jerey_Jobs    Version:0.1    Date: 
Description：搜索数据，找到对应ID的用户
Funcion List: int menu(LINK *head)
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
 Function:       int my_search(LINK *head)
 Description:    在链表中找到对应ID的结点并输出
 Calls:          int menu(LINK *head)
 Called By:      int check_putin(LINK *head)
 Input:          LINK *head
 Return:         no
 *************************************************/ 
int my_search(LINK *head)
{
    system("clear");            //清屏

    char name[MAX];              //待查找姓名

    printf("\t\t\033[47;31mplease input the name : \033[0m");
    gets(name);

    LINK tmp = (*head)->next;   //从头结点的下一个开始查找

    /*遍历链表找到对应ID的数据并输出*/
    while(tmp != NULL)
    {
        if(my_strcmp(tmp->name,name) == 0)
        { 
            printf("\t\t\033[47;31mID          :   %d\033[0m\n",tmp->num);
            printf("\t\t\033[47;31mname        :   %s\033[0m\n",tmp->name);
            printf("\t\t\033[47;31mphonenumber :   %s\033[0m\n",tmp->phonenum);
            printf("\t\t\033[47;31maddress     :   %s\033[0m\n",tmp->address);
            printf("\t\t\033[47;31mhomephone   :   %s\033[0m\n",tmp->homephone);
            printf("\t\t\n");
 
        }
            tmp = tmp->next;
    }

    printf("\n");
    printf("\n");

    printf("按任意键返回主界面！");
    
    getchar();                 
    
    scanf("%*[^\n]");            //进入主菜单界面前清空行输入缓冲，避免报错
    
    menu(head);

    return SUCCESS;
}
