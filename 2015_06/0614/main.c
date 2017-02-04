#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char name[100];
	int age;
	char addr[100];
	struct node *next;
};

struct node *head=NULL;
char name[100],addr[100];
int age;

void insert()
{
	struct node *p,*q,*stu;

	stu=(struct node *)malloc(sizeof(struct node));
	printf("name:");
	scanf("%s",stu->name);
	printf("\nage:");
	scanf("%d",&stu->age);
	printf("\naddr:");
	scanf("%s",stu->addr);

	q=head;
	p=stu;

	if(head == NULL)
	{
		head=p;
		p->next=NULL;
	}
	else
	{
		while(q->next != NULL) q=q->next;
		q->next=p;
		p->next=NULL;
	}
}

void delete()
{
	struct node *p,*q;
	char stu[100] = {0};

	setbuf(stdin, NULL);
	printf("name:\n");
	gets(stu);
	//printf("##%s\n",stu);
	p=head;
	while(strcmp(stu,p->name)!=0&&p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	if(strcmp(stu,p->name)==0)
	{
		if(p==head)
			head=p->next;
		else
			q->next=p->next;
	}
}

void find()
{
	struct node *p,*q;
	char stu[100] = {0};

	p=head;
	printf("name\n");
	gets(stu);
	while(strcmp(stu,p->name)!=0&&p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	if(strcmp(stu,p->name)==0)
	{
		printf("%s  %d  %s",p->name,p->age,p->addr);
	}
}

void print()
{
	struct node *t;
	t=head;
	while(t!=NULL)
	{
		printf("%s  %d  %s",t->name,t->age,t->addr);
		t=t->next;
		printf("\n");
	}
	printf("\n");
}


int main()
{
	int n;
	while(1)
	{
		setbuf(stdin, NULL);
		printf("please input 1234:::");
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			insert();
			break;
		case 2:
			delete();
			break;
		case 3:
			print();
			break;
		case 4:
			find();
			break;
		default:
			break;
			n=0;
		}
		
	}
	return 0;
}
