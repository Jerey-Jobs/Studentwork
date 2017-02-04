/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int func(int x)
{
    int count = 0;
    
    while(x)
    {
        count++;
        x = x & (x - 1);
    }

    return count;
}

int main()
{
    for(;1;)
    printf("%d\n",func(127));
    return 0;
}
