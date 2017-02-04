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
      (*head)->num = 1;
}


void tail_insert(LINK *head,LINK *newnode)
{
    LINK tmp = (*head)->next;

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

    LINK tmp = (*head);
    LINK flag;

    while(delete_num != num)
    {
        count++;

        flag = tmp->next;    

        if(count == 3)
        {
            
            delete_node(head,&tmp);

            count = 0;

            delete_num++;
        }

        tmp = flag;
     
    }
    printf("%d\n",tmp->num);
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

    for(i = 0; i < num - 1; i++)
    {
        newnode = (LINK)malloc(sizeof(NODE));
        
        if(newnode == NULL)
        {
            printf("malloc error!\n");
            exit(1);
        }

        newnode->num = i + 2;
        
        tail_insert(&head,&newnode);
    }
    
 
    find_num(&head,num);

    return 0;
}
