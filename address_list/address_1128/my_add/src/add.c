/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name： add.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/11/15
Description：增加用户函数，且增加完毕询问是否要继续增加，若不则返回主界面
Funcion List: 
             1. int my_judge(LINK *head)
             2. int my_add(LINK *head)
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:       int my_judge(LINK *head)
Description:    判断用户是否要继续输入
Calls:          my_add(LINK *head)
                menu(LINK *head)
Called By:      my_add(LINK *head)
Input:          LINK *head   链表头指针
Return:         no
*************************************************/ 
int my_judge(LINK *head)
{
    char judge;                     //存放输入字符
    
    printf("是否要继续输入(Y/N): ");
    scanf("%c",&judge);
    
    
    if(judge == 'Y' || judge == 'y')//若输入y或Y 则调用my_add继续执行输入
    {
        setbuf(stdin,NULL);
        scanf("%*[^\n]");           //清除输入缓冲
        my_add(head);
    }

    if(judge == 'N' || judge == 'n')//若输入n或N 则返回主界面
    {
        scanf("%*[^\n]");           //清除输入缓冲
        menu(head);                 //调用主界面函数
    }
    
    if((judge != 'Y') && (judge != 'N'))  //若不是n和y则提示重新输入 继续调用judge函数
    {
        printf("错误！请重新输入！\n"); 
       
        my_judge(head);
    }

    return SUCCESS;
}


/*************************************************
Function:       int my_add(LINK *head)
Description:    增加数据
Calls:          my_judge(LINK *head)
Called By:      my_judge(LINK *head)
                check_putin(LINKE *head)
Input:          LINK *head
Return:         no
*************************************************/ 
void my_add(LINK *head)
{
    system("clear");                        //第一时间清屏保证界面整洁
 
    LINK newpeople;                         //新增用户

    newpeople = (LINK)malloc(sizeof(NODE));  
    
    if(newpeople == NULL)
    {
        printf("ADD malloc error!\n");

        return exit(FAIL);
    }

    srand((unsigned)time(NULL));  
    newpeople->num = rand()%1000;            //初始化新联系人的ID

    printf("ID  :                          %d\n",newpeople->num);
    
    /*读取输入*/
    setbuf(stdin,NULL);
    printf("please input the name:         ");        
    gets(newpeople->name);

    printf("please input phonenumber:      ");
    gets(newpeople->phonenum);

    printf("please input the address:      ");
    gets(newpeople->address);

    printf("please input the homephone:    ");
    gets(newpeople->homephone);

    /*若为第一个用户 直接插入即可*/
    if((*head)->next == NULL)
    {
        newpeople->next = (*head)->next;           
        (*head)->next = newpeople;
        write_to_file(head);
        my_judge(head);
    }

    /*找出该插入的位置 插入新用户*/
    LINK tmp = *head;           //前指针
    LINK ptr = tmp->next;       //后指针

    while(ptr != NULL)
    {
        if(my_strcmp(ptr->name,newpeople->name) > 0)  //若后指针的用户名大于新用户的名字
        {
            newpeople->next = tmp->next;              //将新用户插到该用户前面即 前指针的后面
            tmp->next = newpeople;

            write_to_file(head);
            my_judge(head);
        }

        tmp = ptr;
        ptr = ptr->next;
    }

    /*若不存在比新用户名称大的结点 直接插入到最后*/
    tmp->next = newpeople;                      
    newpeople->next = NULL;

    write_to_file(head);

    my_judge(head);                                   //返回主菜单
}

