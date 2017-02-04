#include <stdio.h>

#define MAX 100

struct node
{
   int num;

   struct node *next;
};

typedef struct node Node;
typedef Node * Link;

void create_link(Link *head)
{
    *head = NULL;
}

int insert_head_node(Link *head, Link *newnode)
{
    (*newnode)->next = *head;
    *head = *newnode;
}

void display_link(Link *head)
{   
    Link temp = *head;
    
    while(temp != NULL)
    {
        printf("%d\n",temp->num);
	temp = temp->next;
    }
}

int insert_tail_node(Link *head, Link *newnode)
{
    if(*head == NULL)
    {
        (*newnode)->next = *head;
	*head = *newnode;
    }
    else
    {

        Link temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = *newnode;
        (*newnode)->next = NULL;

    }
}

int insert_mid_node(Link *head, Link *newnode, int num)
{
    if(*head == NULL)
    {
        return -1;
    }

    Link temp = *head;

    while(temp != NULL)
    {
        if(temp->num == num)
	{
	    (*newnode)->next = temp->next;
	    temp->next = *newnode;
	    return 1;
	}

	temp = temp->next;
    }

    return -1;
}

int delete_node(Link *head, int num)
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

    Link ptr = *head;
    Link temp = ptr->next;

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

int main()
{
    Link head;//head = NULL;
    
    create_link(&head);

    Link temp = NULL;

    int i;
    for(i = 0; i < 10; i++)
    {
        temp = (Link)malloc(sizeof(Node));
        temp->num = i + 1;
        insert_tail_node(&head,&temp);
    }

    display_link(&head);

    temp = (Link)malloc(sizeof(Node));
    temp->num = 11;
    insert_mid_node(&head,&temp,10);

    delete_node(&head,11);
    display_link(&head);

    return 0;
}