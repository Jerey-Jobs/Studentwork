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
    system("clear");

    int ID;

    printf("\t\t\033[47;31mplease input the ID : \033[0m");
    scanf("%d",&ID);

    LINK tmp = (*head)->next;

    while(tmp != NULL)
    {
        if(tmp->num == ID)
        { 
            printf("\t\t\033[47;31mID          :   %d\033[0m\n",tmp->num);
            printf("\t\t\033[47;31mname        :   %s\033[0m\n",tmp->name);
            printf("\t\t\033[47;31mphonenumber :   %s\033[0m\n",tmp->phonenum);
            printf("\t\t\033[47;31maddress     :   %s\033[0m\n",tmp->address);
            printf("\t\t\033[47;31mhomephone   :   %s\033[0m\n",tmp->homephone);
            
 
        }
            tmp = tmp->next;
    }

    printf("\n");
    printf("\n");

    printf("按任意键返回主界面！");
    
    getchar();
    
    scanf("%*[^\n]");
    
    menu(head);

    return SUCCESS;
}
