/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <malloc.h>

struct node
{
    int num;

    struct node *pre;
    struct node *next;
};

typedef struct node NODE;
typedef NODE * LINK;

void creat_list(LINK *head)
{
    *head = (LINK)malloc(sizeof(NODE));
    (*head)->next = *head;
    (*head)->pre = *head;
}

int head_insert(LINK *head,LINK *newnode)
{
    LINK tmp = *head;

    (*newnode)->next = (*head)->next;
    (*newnode)->pre = (*head)->next->pre;
    (*head)->next->pre = (*newnode);
    (*head)->next = (*newnode);
}

int tail_insert(LINK *head,LINK *newnode)
{
    LINK tmp = *head;
    
    tmp->pre->next = *newnode;
    (*newnode)->pre = tmp->pre;
    (*newnode)->next = *head;
    (*head)->pre = *newnode;

}

int delete_node(LINK *head,int num)
{
    LINK tmp = (*head)->next;

    while(tmp != *head)
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
}


int my_display(LINK head)
{
    LINK tmp = head->next;

    while(tmp != head)
    {
        printf("%d ",tmp->num);

        tmp = tmp->next;
    }
    printf("\n");
    printf("%d ",tmp->pre->pre->num);
    printf("\n");
}

int main()
{
    LINK head;

    creat_list(&head);

    LINK newnode;
    int i;
    
    for(i = 0; i < 10; i++)
    {
        newnode = (LINK)malloc(sizeof(NODE));

        if(newnode == NULL)
        {
            printf("malloc error!\n");
            exit(1);
        }

        newnode->num = i + 1;
      //  head_insert(&head,&newnode);
        tail_insert(&head,&newnode);
    }

    delete_node(&head,4);

    my_display(head);

    return 0;
}
