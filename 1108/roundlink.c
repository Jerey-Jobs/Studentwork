/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

struct student
{
    int num;

    struct student *next;
};

typedef struct student NODE;
typedef struct student * LINK;

void creat_list(LINK *head)
{
    *head = NULL;
}

void tail_insert(LINK *head,LINK *newnode)
{
    if(*head == NULL)
    {
        *head = *newnode;
        (*newnode)->next = *head;
    }
    else
    {
        LINK temp = *head;

        while(temp->next != *head)
        {
            temp = temp->next;
        }

        temp->next = *newnode;

        (*newnode)->next = *head;
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
            tmp->next = (*newnode);

            return 1;
        }

        tmp = tmp->next;
    }

    if(tmp->num = num)
    {
            (*newnode)->next = tmp->next;
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


    LINK point = *head;
    LINK tmp = point->next;

    while(tmp->next != *head)
    {
        if(tmp->num == num)
        {
            point->next = tmp->next;
            free(tmp);
            tmp = NULL;
            return 1;
        }
  
        point = tmp;
        tmp = tmp->next;
    }

    if(tmp->num == num)
    {
        point->next = tmp->next;
        free(tmp);
        tmp = NULL;
    }

}

int my_display(LINK head)
{
    LINK tmp = head;

    while(tmp->next != head)
    {
        printf("%d ",tmp->num);

        tmp = tmp->next;
    }
     
    printf("%d ",tmp->num);

    printf("\n");

}


int main()
{
    LINK head;
    
    creat_list(&head);

    LINK tmp = NULL;
    int i;
    for(i = 0; i < 10; i++)
    {
        tmp = (LINK)malloc(sizeof(NODE));

        tmp->num = i + 1;

        tail_insert(&head,&tmp);
    }
    
    tmp = (LINK)malloc(sizeof(NODE));
    tmp->num = 100;

    mid_insert(&head,&tmp,5);
    
    delete_node(&head,10);

    my_display(head);

    return 0;
}
