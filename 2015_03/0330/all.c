#include <stdio.h>

int flag[10] = {0};
int n;
int a[10];

int dfs(int step)
{
	int i;
	if(step == (n+1))
	{
		for(i = 1; i <= n; i++)
		{
			printf("%d",a[i]);
		}
		printf("\n");
		return 0;
	}

	for(i = 1; i <= n; i++)
	{
		if(flag[i] == 0)
		{
			flag[i] = 1;
			a[step] = i;
			dfs(step + 1);
			flag[i] = 0;
		}
	}
}

int main()
{
	n = 3;
	dfs(1);

	system("pause");

	return 0;
}

