/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int my_min(int num1,int num2,int num3)
{
    int min = num1;
    
    if(min > num2)
    {
        min = num2;
    }

    min = (min > num3)?num3:min;

    return min;
}

int main()
{
    int num1;
    int num2;
    int num3;
    int min;

    printf("please input 3 number:");
    scanf("%d %d %d",&num1,&num2,&num3);

    min = my_min(num1,num2,num3);

    printf("the min number is:%d\n",min);

    return 0;
}
