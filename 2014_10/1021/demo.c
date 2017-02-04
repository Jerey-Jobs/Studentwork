/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

struct student
{
    char sex;
    int num;
    char name[];
//    char addr[100];
};

int main()
{
    struct student jerey;
    struct student *p;
    p = &jerey;

    p->num = 222;
    p->sex =  'm';

    printf("name = %d\n",jerey.num);

    printf("name = %c\n",jerey.sex);

    printf("sizeof = %d\n",sizeof(jerey));

    return 0;
}
