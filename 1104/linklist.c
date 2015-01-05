/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <malloc.h>
struct student
{
    int date;
    struct student *next;
};

int n;

struct student *creat(void)
{
    struct student *head;
    struct student *p1;
    struct student *p2;
    n = 0;
    p1 = p2 = (struct student *)malloc(sizeof(struct student));
    scanf("%d",&p1->date);
    head = NULL;
    while(p1->date != 0)
    {
        n++;
        if(n == 1)
        {
            head = p1;
        }
        else 
        {
            p2->next = p1;
        }

        p2 = p1;
        
        p1 = (struct student *)malloc(sizeof(struct student));
        
        scanf("%d",&p1->date);
    }

    p2->next = NULL;
    return head;

}

void my_printf(struct student *head)
{
    struct student *p;
    printf("the %d date is : ",n);
    p = head;
    if(head != NULL)
    {
        while(p != NULL)
        {
            printf("%d\n",p->date);
            p = p->next;
        }
    }
}

struct student *insert(struct student *head,int date,int num)
{
    struct student *q;
    struct student *p;
    struct student *new = (struct student *)malloc(sizeof(struct student));
    s->date = date;

    if(head->next == NULL)
    {
        head->next = s;
        s->next = NULL;
    }
    else
    {
        q = head;
        p = head->next;
        while(p != NULL)
        {
            i
        }
    }

    

}

int main()
{
    struct student *head = NULL;

    head = creat();
    
    printf("the date is: \n");
 
    my_printf(head);

    return 0;
}
