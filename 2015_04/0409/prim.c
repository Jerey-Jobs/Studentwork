#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	int j;
	int k;
	int n,m;
	int min;
	int t1,t2,t3;
	int a[50][50];
	int book[50] = {0};
	int dis[50];
	int count = 0;
	int sum = 0;

    scanf("%d%d",&n,&m);

	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
             a[i][j] = 9999;
		}
	}

	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		a[t1][t2] = t3;
		a[t2][t1] = t3;
	}

    for(i = 1; i <= n; i++)
    {
    	dis[i] = a[1][i];
    }

    book[1] = 1;
    count++;

    while(count < n)
    {
    	min = 999;
    	for(i = 1; i <= n; i++)
    	{
    		if(book[i] == 0 && dis[i] < min)
    		{
    			min = dis[i];
    			j = i;
    		}
    	}

    	book[j] = 1;
    	count++;
    	sum = sum + dis[j];


    	for(k = 1; k <= n; k++)
    	{
    		if(book[k] == 0 && dis[k] > a[j][k])
    		{
    			dis[k] = a[j][k];
    		}
    	}
    }

    printf("%d",sum);

    getchar();
    getchar();
	return 0;
}


