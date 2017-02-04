#include <stdio.h>

int func(int a,int b,int i,int j)
{
    int c;
    int max;
    int multi = i * j;
    c = i % j;
  
    while(c != 0)
    {
        i = j;
        j = c;
        c = i % j;
    }

    max = multi / j;

    if(j == a && max == b)
    {
    	return 0;
    }
    else
    {
    	return 1;
    }
}


int main()
{
	int count = 0;

	int i;
	int j;

	int numa,numb;

	scanf("%d%d",&numa,&numb);

	int max = numa * numb;

	for(i = 1; i <= max; i++)
	{
		for(j = 1; j <= max ; j++)
		{
			if(func(numa,numb,i,j) == 0)
			{
				count++;
			}
		}
	}

	printf("%d",count);
}
