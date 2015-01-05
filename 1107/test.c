/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
 *****************************************************/

#include <stdio.h>

struct node
{
    int num;

    struct node *next;
};

typedef struct node NODE;
typedef struct node * LINK;

int creat(LINK *head)
{
    *head = NULL;
}

int head_insert(LINK *head,LINK *tmp)
{
    (*tmp)->next = *head;
    *head = *tmp;
}


int tail_insert(LINK *head,LINK *newnode)
{
    if(*head == NULL)
    {
        (*newnode)->next = *head;
        *head = *newnode;
    }
    else
    {
        LINK tmp = *head;

        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = *newnode;
        (*newnode)->next = NULL;
    }
}

int middle_insert(LINK *head,int num,LINK *newnode)
{
    if(*head == NULL)
    {
        return -1;
    }

    LINK tmp = *head;

    while(tmp->next != NULL)
    {
        if(tmp->num == num)
        {
            (*newnode)->next = tmp->next;
            tmp->next = (*newnode);
            return 1;
        }

        tmp = tmp->next;
    }

    return -1;
}


int delete_node(LINK *head,int num)
{
    if(*head == NULL)
    {
        return -1;
    }

    if((*head)->num == num)
    {
        *head = (*head)->next;
        return 1;
    }

    LINK ptr = *head;
    LINK temp = ptr->next;

    while(temp != NULL)
    {
        if(temp->num == num)
        {
            ptr->next = temp->next;
            free(temp);
            temp = NULL;
            return 1;
        }

        ptr = temp;
        temp = temp->next;
    }

    return -1;
}

int my_display(LINK *head)
{
    LINK tmp = *head;

    while(tmp != NULL)
    {
        printf("num is : %d\n",tmp->num);

        tmp = tmp->next;
    }
}

int main()
{
    int i;
    LINK head;

    creat(&head);

    LINK tmp = NULL;

    for(i = 0; i < 10; i++)
    {
        tmp = (LINK)malloc(sizeof(NODE));

        tmp->num = i + 1;

        tail_insert(&head,&tmp);
    }

    LINK mid = (LINK)malloc(sizeof(NODE));
    
    mid->num = 100;

    middle_insert(&head,5,&mid);

    delete_node(&head,3);

    my_display(&head);

    return 0;
}
