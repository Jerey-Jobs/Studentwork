#include <stdio.h>

int main()
{
	int i = 0;
	int sum = 0;
	int n;
	int a;
	int b;

	scanf("%d",&n);

	for(;sum < n; i++)
	{
		sum += i;
	}

	i -= 1;
    a = sum - n + 1; 
    b = i + 1 - a;

	if((i - 1) % 2 == 0)
	{
		printf("%d/%d",a,b);
	}
	else
	{
		printf("%d/%d",b,a);
	}

}

