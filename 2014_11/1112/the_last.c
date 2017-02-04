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

void creat(LINK *head)                    //建立循环表第一个数1
{
      *head = (LINK)malloc(sizeof(NODE));
      (*head)->next = *head;
      (*head)->num = 1;
}


void tail_insert(LINK *head,LINK *newnode)//尾插入法插入2到n
{
    LINK tmp = (*head)->next;             //从第二个结点开始插入

    while(tmp->next != *head)
    {
        tmp = tmp->next;
    }

    tmp->next = *newnode;                 //插入结点
    
    (*newnode)->next = *head;             //构建头尾相连

}


int find_num(LINK *head,int num)
{
    int count = 0;                //计数
    int delete_num = 0;           //被t出的人数

    LINK tmp = (*head);           //前指针
    LINK flag = tmp;              //后指针,为了计数第一个，后指针先不初始化


    while(delete_num != num)
    {
        count++;

        /*如果该结点数到3 用前后指针删除该结点*/
        if(count == 3)
        {  
            tmp->next = flag->next;

            count = 0;

            delete_num++;
        }

        tmp = flag;                
        flag = flag->next;    
     
    }

    printf("the last people is %d\n",flag->num);    //输出最后结点的数据即为第几个数
}

int main()
{
    LINK head;

    creat(&head);                      //创建第一个结点             
 
    LINK newnode;
    int i;
    int num;                           //人数
    
    printf("please input the num : ");
     scanf("%d",&num);

    /*在第一个结点后插入2到n*/
    for(i = 0; i < num - 1; i++)         
    {
        newnode = (LINK)malloc(sizeof(NODE));
        
        /*判断malloc是否成功*/
        if(newnode == NULL)
        {
            printf("malloc error!\n");
            exit(1);
        }

        newnode->num = i + 2;
        
        tail_insert(&head,&newnode);   //尾插入法插入各结点
    }
    
    find_num(&head,num);               //找到最后的结点并输出该结点的数据 即为第几个

    return 0;
}
