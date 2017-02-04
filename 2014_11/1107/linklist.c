/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAIL -1

struct node       
{
    int num;
    
    struct node *next;
};

typedef struct node NODE;
typedef struct node * LINK;

/*将头指针置空即创建了链表*/
void creat_list(LINK *head)
{
    *head = NULL;                    
}

/*头插入法插入数据*/
void head_insert(LINK *head,LINK *newnode)
{
    (*newnode)->next = *head;      //先让插入数据的链接域指向最前面的一个数据
    *head = *newnode;              //让头指针指向新数据
}

/*尾插入法插入数据*/
void tail_insert(LINK *head,LINK *newnode)
{
    
    if(*head == NULL)              //异常处理，若链表位空直接插入   
    {
        (*newnode)->next = *head;
        *head = *newnode;
    }
    else
    {
        LINK tmp = *head;          //使用tmp代替避免移动头指针

        while(tmp->next != NULL)   //将指针移到链表结尾
        {
            tmp = tmp->next;
        }

        tmp->next = *newnode;      //在链表末参入该数据
        (*newnode)->next = NULL;

    }
}

/*在中间num后面插入数据*/
int mid_insert(LINK *head,LINK *newnode,int num)
{
    /*入口检查，若链表为空，则返回FAIL*/
    if(*head == NULL)
    {
        printf("the linklist is NULL!\n");
        return FAIL;
    }

    LINK tmp = *head;                  //避免移动头指针

    while(tmp->next != NULL)           //遍历链表   
    {
        /*若tmp指向的num等于 num 将新数据插入*/
        if(tmp->num == num)
        {
            (*newnode)->next = tmp->next;   //新数据的指针域指向下一个数据
            tmp->next = (*newnode);         //该数据的指针域指向新数据
            
            return SUCCESS;
        }

        tmp = tmp->next;
    }

    return FAIL;
}


/*删除链表中num数据*/
int delete_node(LINK *head,int num)
{
    /*入口检查，若链表为空，则返回*/
    if(*head == NULL)
    {
        printf("the linklist is NULL!\n");
        return FAIL;
    }
    
    /*若链表第一个即为要删除的数，头指针移向下一个即可*/
    if((*head)->num == num)
    {
        *head = (*head)->next;

        return SUCCESS;
    }

    LINK ptr = *head;              //保护头指针
    LINK tmp= ptr->next;           //定义前后指针

    while(tmp->next != NULL)       //遍历链表
    {
        /*若后指针指向的数据等于num 前指针指向的next为后指针的next */
        if(tmp->num == num)       
        {
            ptr->next = tmp->next;
            free(tmp);             //避免内存泄露
            tmp = NULL;            //避免野指针

            return SUCCESS;
        }
       
        ptr = tmp;
        tmp = tmp->next;    
    }

    return FAIL;
}

int reverse_list(LINK *head)
{
    /*入口检查，若链表为空，则返回*/
    if(*head == NULL)
    {
        printf("the linklist is NULL!\n");
        return FAIL;
    }

    /*入口检查，若链表只有一个结点，则返回*/
    if((*head)->next == NULL)
    {
        printf("the linklist only have 1 node!\n");
        return FAIL;
    }

    
    LINK ptr = *head;             //前指针
    LINK tmp = ptr->next;         //后指针
    LINK flag = NULL;             //中间变量

    /*当后指针不为空时*/
    while(tmp != NULL)        
    {
        flag = tmp->next;         //存储后指针指向的下一个
        tmp->next = ptr;          //令后指针指向的下一个为前指针
        ptr = tmp;                //前指针移动到后指针的位置
        tmp = flag;               //后指针移动到下一个结点
    }

    (*head)->next = NULL;         //定义链表尾
    (*head) = ptr;                //从新定义头指针
}

/*遍历该链表并输出*/
void my_display(LINK head)
{
    while(head != NULL)
    {
        printf("%d ",head->num);

        head = head->next;
    }
    printf("\n");
}



int main()
{
    int i;
    LINK head;                   //链表头指针
    LINK newnode = NULL;         //代插入数据

    creat_list(&head);           //创建链表
    
    for(i = 0; i < 10; i++)   
    {
        newnode = (LINK)malloc(sizeof(NODE));

        if(newnode == NULL)      //malloc检查
        {
            printf("malloc error!\n");
            exit(FAIL);
        }

        newnode->num = i + 1;    
        
        tail_insert(&head,&newnode);        //尾插入法插入10个数据
    }

    printf("初始链表为 : ");
    my_display(head);                       //输出该链表
    
    newnode = (LINK)malloc(sizeof(NODE));   

    newnode->num = 100;

    mid_insert(&head,&newnode,5);           //在5的后面插入新数据

    printf("插入后链表为 : ");
    my_display(head);                       //输出该链表

    delete_node(&head,3);                   //删除3这个数据
    
    printf("删除后链表为 : ");
    my_display(head);                       //输出该链表

    reverse_list(&head);

    printf("逆序后为 : ");
    my_display(head);                       //输出该链表
    
    return 0;
}


