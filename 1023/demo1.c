/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int func(int num1,int num2)
{
    printf("num1 = %d\n",num1);
    printf("num2 = %d\n",num2);
}

int main()
{

    int i = 2;

    func(i++,++i);
    return 0;
}
