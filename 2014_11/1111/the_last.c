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
    (*head)->num = -111;
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


int delete_node(LINK *head,LINK *point)
{

    LINK ptr = (*head)->next;
    LINK tmp = ptr->next;

    while(tmp != *head)
    {
        if(tmp->num == (*point)->num)
        {
            ptr->next = tmp->next;
                
            free(tmp);

            tmp = NULL;

            return SUCCESS;
        }

        ptr = tmp;
        tmp = tmp->next;
            
    }
    
    return SUCCESS;
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
}

int find_num(LINK *head,int num)
{
    int count = 0;
    int delete_num = 0;

    LINK tmp = (*head)->next;
    LINK flag = tmp;

    while(delete_num != (num - 1))
    {
        
        flag = tmp;

        if(tmp == *head)
        {
            tmp = tmp->next;
        }
        
        count++;
        
        if(count == 3)
        {
            count = 0;
          //  flag = tmp;

            delete_node(head,&tmp);
            
        //    tmp = flag->next;

            delete_num++;

        }

        tmp = flag->next;

    }
}


int main()
{
    LINK head;

    creat(&head);

    LINK newnode;
    int i;
    int num;
    
    printf("please input the num : ");
    scanf("%d",&num);

    for(i = 0; i < num; i++)
    {
        newnode = (LINK)malloc(sizeof(NODE));
        
        if(newnode == NULL)
        {
            printf("malloc error!\n");
            exit(1);
        }

        newnode->num = i + 1;
        
        tail_insert(&head,&newnode);
    }
 
    find_num(&head,num);

    my_display(head);

    return 0;
}
