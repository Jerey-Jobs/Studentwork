#include <stdio.h>

int main()
{
    int i;
    int num[100];

    num[0] = 1;
    num[1] = 1;

    for(i = 2; i < 100; i++)
    {
        num[i] = num[i - 1] + num[i - 2];
    }

    int n;
    scanf("%d",&n);

    printf("%d",num[n - 1]);

	return 0;
}
