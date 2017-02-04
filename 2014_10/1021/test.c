/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

union node
{
    char c;
    int num;
};

int main()
{

    union node p;

    p.num = 1;
 //   p.c = 0;
    printf("%d\n",p.c);

    return 0;
}
