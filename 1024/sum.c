/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int main()
{
    int sum = 0;
    int i = 0;

loop:if(i <= 100)
     {
         sum += i;
         i++;
         goto loop;
     }

    printf("sum is  %d\n",sum);
    return 0;
}
