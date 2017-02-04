/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int count;

int function(int n)
{
    if(n == 1)
    {
        return count;
    }
    else
    {
        if(n % 2 == 1)
        {
            count++;
            function(3 * n + 1);
        }
        else
        {
            count++;
            function(n / 2);
        }
    }
}


int main()
{
    int n;
    int i;
    int a[100];

    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i = 0; i < n; i++)
    {
        count = 0;
        printf("%d\n",function(a[i]));
    }

    return 0;
}
