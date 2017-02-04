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
    int i;
    int j;
    int n;
    int tmp;
    int num[100];

    int flag = 0;

    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }

    for(i = 0; i < n - 2; i++)
    {
    	for(j = 0; j < n - 1 - i; j++)
    	{
             if(num[j] > num[j + 1])
             {
             	tmp = num[j];
             	num[j] = num[j + 1];
             	num[j + 1] = tmp;
             }
    	}
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ",num[i]);
    }

    return 0;
}
