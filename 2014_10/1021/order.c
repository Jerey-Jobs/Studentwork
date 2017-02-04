/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int order(int *p)
{
    int i;
    int j;
    int tmp;

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9 - i; j++)
        {
            if(*(p + j) > *(p + j + 1))
            {
                tmp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = tmp;
            }
        }
    }
}

int main()
{
    int i;
    int src[10];

    printf("input 10 number : ");
    for(i = 0; i < 10; i++)
    {
        scanf("%d",&src[i]);
    }

    order(src);

    printf("output ordering munber is :");
    for(i = 0; i < 10; i++)
    {
        printf("%d ",src[i]);

    }
    printf("\n");
    return 0;
}
