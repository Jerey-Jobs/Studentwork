/**
 * @author evan
 * @date 2015/06/27
 */


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
  printf("age:");
  scanf("%d",&stu->age);
  printf("address:");
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
  char stu[100];

  if(head == NULL)
  {
      printf("empty!\n");
   	  return;
  }
  
  p=head;
  printf("name");
  scanf("%s",stu);
  while(strcmp(stu,p->name)!=0&&p->next!=NULL)
  {
    q=p;
    p=p->next;
  }
  if(strcmp(stu,p->name)==0)
  {
    if(p==head)  head=p->next;
    else
	  q->next=p->next;
  }
}

void find()
{
  struct node *p;
  char stu[100];

  if(head == NULL)
  {
      printf("empty!\n");
   	  return;
  }
  
  p=head;
  printf("name:");
  scanf("%s",stu);
  while(strcmp(stu,p->name)!=0&&p->next!=NULL)
  {
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

  if(head == NULL)
  {
      printf("empty!\n");
   	  return;
  }
  
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
		printf("1:insert\n2:delete\n3:print\n4:find\n5:quit\n\n");
      scanf("%d",&n);
	  switch(n)
      {
        case 1:                //²åÈë½Úµã 
          insert();
          break;
        case 2:
          delete();           //delete node by name 
          break;
        case 3:
          print();
          break;
        case 4:
		  find();           //find node by name
          break;
	  case 5:
		  exit(0);          //quit
		  break;          
        default:
          break;
      }
      n=0;
    }
	return 0;
}





