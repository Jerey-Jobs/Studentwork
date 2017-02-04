/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

enum STACK{FULL,NOTFULL,EMPTY,NOTEMPTY};

int stack[MAX];
int top;

void init_stack()
{
    top = -1;
}

int push_stack(int num)
{
    if(is_stack_full() != FULL)
    {
        top++;
        stack[top] = num;

        return NOTFULL;
    }
    
    return FULL;
}

int is_stack_full()
{
    if(top == MAX - 1)
    {
        return FULL;
    }

    return NOTFULL;
}


int is_stack_empty()
{
    if(top == -1)
    {
        return EMPTY;
    }

    return NOTEMPTY;
}

int pop_stack()
{
    if(is_stack_empty() != EMPTY)
    {
        return stack[top--];
    }

    return EMPTY;
}

int main()
{
    init_stack();

    int i;

    for(i = 0; i < 5; i++)
    {
        push_stack(i + 1);
    }


    for(i = 0; i < 5; i++)
    {
        printf("%d\n",pop_stack());
    }


    return 0;
}
