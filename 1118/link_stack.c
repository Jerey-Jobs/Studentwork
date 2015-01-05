/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

enum stack{pop_ok,push_ok};

struct node
{
    int num;

    struct node *next;
};

typedef struct node NODE;
typedef struct node * LINK;

void create_list(LINK *head)
{
    *head = NULL;
}

int push_stack(LINK *head,LINK *newnode)
{
    (*newnode)->next = *head;
    *head = *newnode;

    return push_ok;
}

int pop_stack(LINK *head)
{
    int tmp = (*head)->num;

    *head = (*head)->next;
    free(*newnode);

    return tmp;
}

int main()
{
    LINK head;
    LINK newnode;

    create_list(&head);

    int i;
    for(i = 0; i < 5; i++)
    {
        newnode = (LINK)malloc(sizeof(NODE));
        newnode->num = i + 1;

        push_stack(&head,&newnode);
    }

    for(i = 0; i < 5; i++)
    {
        printf("%d\n",pop_stack(&head));
    }

    return 0;
}
