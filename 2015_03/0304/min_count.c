#include <stdio.h>

int main()
{
    int n;
    int i;
    int sum = 0;
    int avrg;
    int num[100];

    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
    	scanf("%d",&num[i]);
    	sum += num[i];
    }

    avrg = sum / n;

    int j = 0;
    int tmp;
    // for(i = 0; i < n; i++)
    // {
    // 	if(num[i] == avrg)
    // 	{
    //         tmp = num[j];
    //         num[j] = num[i];
    //         num[i] = tmp;
    //         j++;
    // 	}
    // }

    int count = 0;
    int result;

    for(i = 0; i < n; i++)
    {
    	if(num[i] != avrg)
    	{
    		tmp = num[i] - avrg;
    		num[i + 1] += tmp;
    		count++;
    	}
    }

    printf("%d",count);

	return 0;
}


