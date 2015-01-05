/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   my_delete.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/11/15
Description：  删除数据函数
Funcion List:  1.int menu(LINK *head)
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
 Function:       void ID_delete(LINK *head)
 Description:    按照id删除用户函数
 Calls:          int menu(LINK *head)
 Called By:      void del_display(LINK *head,char *ptr)
 Input:          LINK *head  
 Return:         no
 *************************************************/ 
void ID_delete(LINK *head)
{
    int ID;                    //待删ID

    printf("\t\t\033[47;31mplease input the ID : \033[0m");
    scanf("%d",&ID);

    LINK ptr = *head;          //前指针
    LINK tmp = ptr->next;      //后指针

    /*遍历链表找到该ID的结点*/
    while(tmp != NULL)         
    {
        if(tmp->num == ID)
        {
            ptr->next = tmp->next;       //删除tmp结点
            
            free(tmp);          
            tmp = NULL;
            
            printf("删除成功，按任意键返回！");   
            getchar();
            getchar();
            
            menu(head);                  //返回主菜单界面
        }

        ptr = tmp;
        tmp = tmp->next;
    }


    /*若未删除成功 提示并返回主菜单界面*/
    printf("未找到该ID的数据！\n");
    printf("按回车键返回！\n");

    getchar();
    getchar();
    scanf("%*[^\n]");
    
    menu(head);                          //返回主菜单

}


/*************************************************
Function:       void del_display(LINK *head,char *ptr)
Description:    打印出重复的用户的数据 并调用用ID删除函数
Calls:          void ID_delete(LINK *head)
Called By:      int my_delete(LINK *head)
Input:          LINK *head  链表头结点
                char *ptr   重复用户的姓名
Return:         no
*************************************************/ 
void del_display(LINK *head,char *ptr)
{
    LINK temp = (*head)->next;

    /*遍历链表找到重复用户 并输出*/
    while(temp != NULL)
    {
        if(my_strcmp(temp->name,ptr) == 0)
        { 
            printf("\t\t\033[47;31mID          :   %d\033[0m\n",temp->num);
            printf("\t\t\033[47;31mname        :   %s\033[0m\n",temp->name);
            printf("\t\t\033[47;31mphonenumber :   %s\033[0m\n",temp->phonenum);
            printf("\t\t\033[47;31maddress     :   %s\033[0m\n",temp->address);
            printf("\t\t\033[47;31mhomephone   :   %s\033[0m\n",temp->homephone);
            printf("\n");    
        }

        temp = temp->next;
    }
    
    printf("请按照ID删除\n");
    ID_delete(head);             //调用 用ID删除函数
}

/*************************************************
Function:       int my_delete(LINK *head)
Description:    删除函数，并返回主页
Calls:          int menu(LINK *head)
Called By:      int check_putin(LINK *head)
Input:          LINK *head   链表头结点
Return:         NO
*************************************************/ 
int my_delete(LINK *head)
{
    system("clear");             

    char del_name[MAX];                //待删除用户姓名
    int count = 0;                     //该姓名用户数

    printf("\t\t\033[47;31mplease input the name : \033[0m");
    gets(del_name);

    LINK temp = (*head)->next;

    /*遍历链表找出该姓名的用户数有几个*/
    while(temp != NULL)
    {
        if(my_strcmp(temp->name,del_name) == 0)
        {
            count++;
        }

        temp = temp->next;
    }

    /*若不存在重名的人，则删除该用户*/
    if(count == 1)
    {
        LINK ptr = *head;          //前指针
        LINK tmp = ptr->next;      //后指针

        /*遍历链表找到该name的结点*/
        while(tmp != NULL)         
        {
            if(my_strcmp(tmp->name,del_name) == 0)
            {
                ptr->next = tmp->next;       //删除tmp结点
            
                free(tmp);          
                tmp = NULL;
            
                printf("删除成功，按任意键返回！");   
                getchar();
                getchar();
         
                menu(head);                  //返回主菜单界面
            }

            ptr = tmp;
            tmp = tmp->next;
        }

    }
    
    /*若存在重名的 调用del_display函数 输出重名用户*/
    if(count > 1)
    {
        printf("存在重复姓名!\n");

        del_display(head,del_name);

    }

    /*若不存在该姓名的用户 提示未找到 并返回*/
    if(count == 0)
    {

        printf("未找到该ID的数据！\n");
        printf("按回车键返回！\n");

        getchar();
        getchar();
        scanf("%*[^\n]");
    
        menu(head);                          //返回主菜单

    }

    return SUCCESS;
}
