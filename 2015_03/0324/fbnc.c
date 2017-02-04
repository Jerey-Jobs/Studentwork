#include <stdio.h>

int n;

int func(n)
{
    if(1 == n || 2 == n)
    {
    	return 1;
    }
    return func(n - 1) + func(n - 2);
}

int main()
{
    scanf("%d",&n);

    printf("%d\n",func(n) % 10007);
}


