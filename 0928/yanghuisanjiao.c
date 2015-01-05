#include<stdio.h>
int main()
{
    int i, j;
    int a[10][10];
    for(i = 0; i < 10; i++)
    {    for(j = 0; j < 10; j++)
        a[i][j]= 0;
    }
    for(i = 1; i < 10; i++)
    { a[i][0]=1;
         for(j = 1; j < 10; j++)
         a[i][j]=a[i-1][j-1]+a[i-1][j];
    }
    for(i = 0; i < 10; i++)
    { 
        for(j = 0; a[i][j] != 0; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
return 0;
}
