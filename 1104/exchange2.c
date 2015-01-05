/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int exchange(int *num1,int *num2)
{
    *num1 += *num2;
    *num2 = *num1 - *num2;
    *num1 -= *num2; 
}

int main()
{
    int num1;
    int num2;

    printf("input the number1 : ");
    scanf("%d",&num1);

    printf("input the number2 : ");
    scanf("%d",&num2);

    exchange(&num1,&num2);

    printf("the number 1 is: %d\n",num1);
    printf("the number 2 is: %d\n",num2);

    return 0;
}
