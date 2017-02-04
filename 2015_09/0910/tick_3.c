#include "stdio.h"
#include "stdlib.h"


i

typedef struct stu
{
	int num;
	int state;
	struct stu *next;
} People,* PeopleLink;

void ListCreate ( PeopleLink *head,int number)
{
	(*head)->num = number;
	(*head)->next = *head;
}

void ListHeadInsert ( PeopleLink *head,PeopleLink *newnode )
{
	(*newnode)->next = (*head);
	(*head)->next = *newnode;
	*head = *newnode;
}

void ListTailInsert ( PeopleLink *head,PeopleLink *newnode )
{
	if ( head == NULL )
	{
		*head = *newnode;
		(*head)->next = *head;
	}
	else
	{
		PeopleLink tmp = *head;

		while (tmp->next != *head )
		{
			tmp = tmp->next;
		}

		tmp->next = *newnode;
		(*newnode)->next = *head;
	}
}

unsigned char ListMidInsert ( PeopleLink *head,PeopleLink *newnode,int number )
{
	if ( head == NULL )
	{
		*head = *newnode;
		(*newnode)->next = *head;
	}
	else
	{
		PeopleLink tmp = *head;

		while ( tmp->next != *head )
		{
			if ( tmp->num == number )
			{
				(*newnode)->next = tmp->next;
				tmp->next = *newnode;
				return 0;
			}

			tmp = tmp->next;
		}
	}

	return -1;
}


unsigned char ListDeleteNode (PeopleLink *head,int number)
{
	/*入口检查，若链表为空，则返回*/
	if ( *head == NULL )
	{
		printf ( "the linklist is NULL!\n" );
		return -1;
	}

	if ((*head)->num == number)
	{
		*head = NULL;
		return;
	}

	PeopleLink point = *head;
	PeopleLink tmp = point->next;

	while (tmp->next != tmp)
	{
		if (tmp->num == number)
		{
			point->next = tmp->next;
			free(tmp);
			tmp = NULL;
			return 0;
		}

		point = point->next;
		tmp = point->next;
	}

	return -1;
}

void ListDisplay(PeopleLink head)
{
	PeopleLink tmp = head;

	while(tmp->next != head)
	{
		printf(" %d %d |", tmp->num,tmp->state);
//		tmp->num = 100;
		tmp = tmp->next;
	}

	printf(" %d %d |\n", tmp->num,tmp->state);
}

int ListReverse(PeopleLink *head)
{
	if(*head == NULL)
	{
		return -1;
	}
	else
		if((*head)->next == *head)
		{
			return -1;
		}
		else
		{
			PeopleLink ptr = *head;
			PeopleLink tmp = ptr->next;
			PeopleLink flag;

			while(tmp->next != *head)
			{
				flag = tmp->next;
				tmp->next = ptr;

				ptr = tmp;
				tmp = flag;
			}

			flag = tmp->next;
			tmp->next = ptr;

			(*head)->next = tmp;
			*head = tmp;

		}


}

void FindResult(PeopleLink head,int n)
{
	PeopleLink tmp = head;
	int DeleteNum = 0;
	int Count = 0;

	while(DeleteNum != (n - 1))
	{
		//	printf(" %d %d |", tmp->num,tmp->state);
		if(tmp->state != 0)
		{
			Count++;

			if(Count == 3)
			{
				Count = 0;
				DeleteNum++;
				tmp->state = 0;
			}
		}



		tmp = tmp->next;
	}



}





int main ( int argc, char const *argv[] )
{
	int i;
	int num;
	scanf("%d",&num);

	PeopleLink head = (PeopleLink)malloc(sizeof(People));
	PeopleLink newnode;

	head->state = 1;
	ListCreate(&head,1);

	for(i = 2; i <= num; i++)
	{
		newnode = (PeopleLink)malloc(sizeof(newnode));
		newnode->num = i;
		newnode->state = 1;
		ListTailInsert(&head,&newnode);
	}

	ListDisplay(head);

//	FindResult(head,num);
	ListReverse(&head);
	ListDisplay(head);
	ListDisplay(head);

	/*	newnode = (PeopleLink)malloc(sizeof(newnode));
		newnode->num = 20;

		ListMidInsert(&head,&newnode,5);
		ListDisplay(head);

		ListDeleteNode(&head,3);
		ListDisplay(head);*/

	return 0;
}


