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

    struct node *next;
};

typedef struct node NODE;
typedef NODE * LINK;

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

        while(tmp != NULL)
        {
            tmp = tmp->next;
        }
        
        tmp->next = *newnode;
        (*newnode)->next = tmp;
    }
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
    LINK head = NULL;

    creat(&head);
    LINK tmp = (LINK)malloc(sizeof(NODE));

    tmp->num = 6;
   
    tail_insert(&head,&tmp);
   
    my_display(&head);

    return 0;
}
