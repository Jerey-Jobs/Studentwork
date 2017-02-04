/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int func(int n)
{
    if(n >= 0)
    {
         return 5;
    }
    else
    {
        return func(n + 1)  + func(n + 2) + 1;
    }
}


int main()
{
    int num;

    scanf("%d",&num);

    printf("%d",func(num));

    return 0;
}
