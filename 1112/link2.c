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
    (*head)->next = *head;
}

void display_link(Link *head)
{   
    Link temp = *head;
    
    while(temp != *head)
    {
        printf("%d\n",temp->num);
	temp = temp->next;
    }
}

int insert_tail_node(Link *head, Link *newnode)
{

        Link temp = *head;

        while(temp->next != *head)
        {
            temp = temp->next;
        }

        temp->next = *newnode;
        (*newnode)->next = *head;

}

int delete_node(Link *head, int num)
{

    Link ptr = *head;
    Link temp = ptr->next;

    while(temp != *head)
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
int count_3(Link *head)
{
    int i = 1;
    int j= 0;
    Link temp = *head;

    while(j != 3)
    {
        if(i % 3 ==0)
	{
	    delete_node(&temp,temp->num);

	    i = 0;

	    j++;
	}

	temp = temp->next;
	i++;
    }
    printf("%d",temp->num);
}

int main()
{
    Link head;//head = NULL;

    head = (Link)malloc(sizeof(Node));    
    
    create_link(&head);

    Link temp = NULL;

    int i;
    
    for(i = 0; i < 3; i++)
    {
        temp = (Link)malloc(sizeof(Node));
        temp->num = i + 1;
        insert_tail_node(&head,&temp);
    }
    count_3(&head);
    display_link(&head);
    
    //reverse_link(&head);
    //display_link(&head);

    #if 0
    temp = (Link)malloc(sizeof(Node));
    temp->num = 5;
    insert_mid_node(&head,&temp,10);

    delete_node(&head,11);
    display_link(&head);
    #endif
    return 0;
}
