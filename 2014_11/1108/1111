/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

struct node
{
    int num;

    struct node *pre;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * LINK;

void creat(LINK *head)
{
    *head = NULL;
}

int tail_insert(LINK *head,LINK *newnode)
{
    if(*head == NULL)
    {
        (*head) = *newnode;
        (*newnode)->pre = *head;
        (*newnode)->next = *head;
    }
    if(*head == NULL)
    {
        printf("the list is NULL!\n");
        return -1;
    }
    else
    {
        LINK tmp = *head;

        while(tmp->next != *head)
        {
            tmp = tmp->next;
        }

        tmp->next = *newnode;
        (*newnode)->pre = tmp;
        (*newnode)->next = *head;
        (*head)->pre = *newnode;
    }
}

int mid_insert(LINK *head,LINK *newnode,int num)
{
    if(*head == NULL)
    {
        printf("the list is NULL!\n");
        return -1;
    }

    LINK tmp = *head;

    while(tmp->next != *head)
    {
        if(tmp->num == num)
        {
            (*newnode)->next = tmp->next;
            (*newnode)->pre = tmp;
            tmp->next->pre = (*newnode);
            tmp->next = (*newnode);

            return 1;
        }
        tmp = tmp->next;
    }

    if(tmp->num == num)
    {
        (*newnode)->next = tmp->next;
        (*newnode)->pre = tmp;
        tmp->next->pre = (*newnode);
        tmp->next = (*newnode);
    }


}

int delete_node(LINK *head,int num)
{
    if(*head == NULL)
    {
        printf("the list is NULL!\n");
        return -1;
    }

    if((*head)->num == num)
    {
        (*head)->pre->next = (*head)->next;
        (*head)->next->pre = (*head)->pre;
        *head = (*head)->next;
    }
    
    LINK tmp = *head; 

    while(tmp->next != *head)
    {
        if(tmp->num == num)
        {
            tmp->pre->next = tmp->next;
            tmp->next->pre = tmp->pre;
            free(tmp);
            tmp = NULL;

            return 1;
        }
        
        tmp = tmp->next;
    }

    if(tmp->num == num)
    {
        tmp->pre->next = tmp->next;
        tmp->next->pre = tmp->pre;
        free(tmp);
        tmp = NULL;
     
    }
    
}


int display_next(LINK head)
{
    LINK tmp = head;

    while(tmp->next != head)
    {
        printf("%d ",tmp->num);

        tmp = tmp->next;
    }
    printf("%d ",tmp->num);
    printf("\n");
    printf("%d ",tmp->next->pre->pre->num);
    printf("\n");
    printf("%d ",tmp->next->next->next->num);
    printf("\n");
}



int main()
{
    LINK head;
    LINK newnode = NULL;

    creat(&head);

    int i;
    for(i = 0; i < 10; i++)
    {
        newnode = (LINK)malloc(sizeof(NODE));

        newnode->num = i + 1;

        tail_insert(&head,&newnode);
    }
    
    newnode = (LINK)malloc(sizeof(NODE));

    newnode->num = 100;

    mid_insert(&head,&newnode,4);

    delete_node(&head,10);

    display_next(head);

    return 0;
}
