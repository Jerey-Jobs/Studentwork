/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int sort(int *p)
{
    int tmp;
    int i;
    int j;

    for(i = 0; i < 4; i++)
    {
        for(j= 0; j < 4 - i; j++)
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
    int num[5];
    int i;

    printf("input 5 number :");
    for(i = 0; i < 5; i++)
    {
         scanf("%d",&num[i]);
    }

    sort(num);

    printf("the ordering number :");
    for(i = 0; i < 5; i++)
    {
         printf("%d ",num[i]);
    }
    printf("\n");

    return 0;
}
