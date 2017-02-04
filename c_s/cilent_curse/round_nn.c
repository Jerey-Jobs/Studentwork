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
    int n;
    int i;
    int j;
    
    int a[100][100] = {0};
    scanf("%d",&n);

    int d = n;
    int t = n * n;
    int b = 1;

    while(b != n -1)
    {
        for(j = d; j >= b; j--)
        {
            a[d][j] = t--;
        }
        for(i = (d - 1); i >= b; i--)
        {
            a[i][b] = t--;
        }

        for(j = b + 1; j <= (n - b); j++)
        {
            a[b][j] = t--;
        }
        for(i = b; i <= d - 1; i++)
        {
            a[i][d] = t--;
        }

        b++;
        d--;
    }

    if(n == 3)
    {
        a[2][2] = 1;
    }

    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
                printf("%3d ",a[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for(i = 1; i <= n; i++)
    {
        if(a[i][i] != a[n - i + 1][i])
        {
            sum = sum + a[i][i] + a[n - i + 1][i];
        }
        else
        {
            sum = sum + a[i][i];
        }
    }

    printf("%d\n",sum);

    return 0;
}
