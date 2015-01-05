//一到n有多少个９
#include<stdio.h>
int main()
{
    int n, i, b;
    int f = 0;
    scanf("%d",&n);
    for(i = 0; i <= n; i++)
    {
        b = found(i);   
        f += b;
    }
    printf("number=%d\n\n",f);
    return 0;
}

int found(int n)
{
    int c, b = 0;
    while (n >= 1)
    {
        
        c = n - (n / 10) * 10;
        n = n / 10;
        if (c==9)
             b++;
    }
 return (b);
}







