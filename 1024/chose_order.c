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
    int a[10];
    int i;
    int j;
    int min;
    int tmp;
    
    printf("please input number:");
    for(i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i = 0; i < 10; i++)
    {
        min = i;

        for(j = i; j < 10; j++)
        { 
            if(a[j] < a[min])
            {
                min = j;
            }
        }

        if(a[i] != a[min])
        {
            tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }

    printf("the ordering number:");
    for(i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}
