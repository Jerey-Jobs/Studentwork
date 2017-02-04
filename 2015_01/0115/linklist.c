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
    *head = NULL;
}

void head_insert(LINK *head,LINK *newnode)
{
    (*newnode)->next = *head;
    *head = *newnode;
}

void tail_insert(LINK *head,LINK *newnode)
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

int mid_insert(LINK *head,LINK *newnode,int num)
{
    if(*head == NULL)
    {
        printf("the list is NULL!\n");
        return FAIL;
    }
    else
    {
        LINK tmp = *head;

        while(tmp->next != NULL)
        {
            if(tmp->num == num)
            {
                (*newnode)->next = tmp->next;
                tmp->next = *newnode;
                
                return SUCCESS;
            }

            tmp = tmp->next;
        }

    }
    
    return SUCCESS;
}


int delete_node(LINK *head,int num)
{
    if(*head == NULL)
    {
        printf("the list is NULL!\n");
        return FAIL;
    }
    else
    {
        LINK tmp = *head;
        LINK tmpnext = tmp->next;

        while(tmp->next != NULL)
        {

            if(tmpnext->num == num)
            {
                tmp->next = tmpnext->next;
                
                free(tmpnext);
 //               tmpnext = NULL;
            }

            tmp = tmpnext;
            tmpnext = tmpnext->next;
            
        }
    }

    return SUCCESS;
}

int reverse(LINK *head)
{
    if(*head == NULL) return -1;

    LINK tmp = (*head);
    LINK p = tmp;

    while(tmp->next != NULL)
    {
        p = tmp->next;
        tmp->next = p->next;
        p->next = (*head);
        (*head) = p;
    }
    // if(*head == NULL || (*head)->next == NULL)
    // {
    //     return -1;
    // }

    // LINK ptr = *head;
    // LINK str = ptr->next;
    // LINK tmp = str->next;

    // while(tmp != NULL)
    // {
    //     str->next = ptr;
    //     ptr = str;
    //     str = tmp;
    //     tmp = tmp->next;
    // }
    // str->next = ptr;

    // (*head)->next = NULL;
    // *head = str;
}

int my_display(LINK head)
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

    head_insert(&head,&newnode);

    //    tail_insert(&head,&newnode);
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
