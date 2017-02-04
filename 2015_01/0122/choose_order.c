/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/
#include <stdio.h>
void choose_order(int *num)
{
    int i;
    int j;
    int max;
    for(i = 0; i < 10; i++)
    {
        max = 0;
        for(j = 1; j < 10 - i; j++)
        {
            if(num[j] > num[max])
            {
                max = j;
            }
        }
        int tmp = num[max];
        num[max] = num[10 - i];
        num[10 - i] = tmp;
    }
}
int min_order(int *n)
{
    int i;
    int j;
    int min;
    for(i = 0; i < 10; i++)
    {
        min = i;
        for(j = i; j < 10; j++)
        {
            if(n[j] < n[min])
            {
                min = j;
            }
        }
        int tmp = n[min];
        n[min] = n[i];
        n[i] = tmp;
    }
}
int main()
{
    int num[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        num[i] = rand()%100;
    }
    for(i = 0; i < 10; i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
    min_order(num);
    for(i = 0; i < 10; i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
//
    return 0;
}
