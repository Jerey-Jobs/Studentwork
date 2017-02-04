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
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main()
{
    int num1;
    int num2;

    int *p1 = &num1;
    int *p2 = &num2;

    printf("input the number1 : ");
    scanf("%d",&num1);

    printf("input the number2 : ");
    scanf("%d",&num2);

    exchange(p1,p2);

    printf("the number 1 is: %d\n",num1);
    printf("the number 2 is: %d\n",num2);

    return 0;
}
