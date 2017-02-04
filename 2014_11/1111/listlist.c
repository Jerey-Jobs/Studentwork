/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/


#include <stdio.h>

#define FAIL -1
#define SUCCESS 0


struct node
{
    int num;

    struct node *next;
};

typedef struct node NODE;
typedef struct node * LINK;

void creat(LINK *head)
{
    *head = (LINK)malloc(sizeof(NODE));
    (*head)->next = *head;
}

void head_insert(LINK *head,LINK *newnode)
{
    (*newnode)->next = (*head)->next;
    (*head)->next = *newnode;
}

void tail_insert(LINK *head,LINK *newnode)
{
    LINK tmp = *head;

    while(tmp->next != *head)
    {
        tmp = tmp->next;
    }

    tmp->next = *newnode;
    
    (*newnode)->next = *head;

}

int mid_insert(LINK *head,LINK *newnode,int num)
{
        LINK tmp = (*head)->next;

        while(tmp->next != *head)
        {
            if(tmp->num == num)
            {
                (*newnode)->next = tmp->next;
                tmp->next = *newnode;
                
                return SUCCESS;
            }

            tmp = tmp->next;
        }
    
    return SUCCESS;
}


int delete_node(LINK *head,int num)
{

        LINK tmp = (*head)->next;
        LINK tmpnext = tmp->next;

        while(tmp->next != *head)
        {

            if(tmpnext->num == num)
            {
                tmp->next = tmpnext->next;
                
                free(tmpnext);
                tmpnext = *head;

                return SUCCESS;
            }

            tmp = tmpnext;
            tmpnext = tmpnext->next;
            
        }
    

    return SUCCESS;
}

int reverse(LINK *head)
{
    if((*head)->next == *head || (*head)->next->next == *head)
    {
        return -1;
    }

    LINK ptr = (*head)->next;
    LINK str = ptr->next;
    LINK tmp = str->next;

    while(tmp != *head)
    {
        str->next = ptr;
        ptr = str;
        str = tmp;
        tmp = tmp->next;
    }
    str->next = ptr;

    (*head)->next->next = *head;
    (*head)->next = str;
}

int my_display(LINK head)
{
    LINK tmp = head->next;

    while(tmp != *head)
    {
        printf("%d ",tmp->num);
        
        tmp = tmp->next;
    }

    printf("\n");
}


int main()
{
    LINK head;

    creat(&head);

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

   // head_insert(&head,&newnode);

        tail_insert(&head,&newnode);
    }
    
    newnode = (LINK)malloc(sizeof(NODE));

    newnode->num = 100;

    mid_insert(&head,&newnode,4);

    delete_node(&head,7);

    my_display(head);
    
    reverse(&head);
    my_display(head);

    return 0;
}
