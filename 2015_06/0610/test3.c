#include <stdio.h>
#include <string.h>

int n;
int highi[400];
int ai[400];
int counti[100];
int sum_count;
int max;
int tmp_high;
int high_flag;

int dfs(int step)
{
	int i;

	if(tmp_high > max)
	{
		max = tmp_high;
		printf("%d\n", tmp_high);
	}

	if(step >= sum_count)
	{
		return 0;
	}

	for(i = 0; i < n; i++)
	{
	
		if((tmp_high + highi[i]) < ai[i] && counti[i] > 0)
		{
			tmp_high += highi[i];

			counti[i]--;
		}
		dfs(step + 1);
		counti[i]++;
		//	tmp_high -= highi[i];
	}

}

int main(int argc, char const *argv[])
{
	int i;
	scanf("%d",&n);

	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d",&highi[i],&ai[i],&counti[i]);
		sum_count += counti[i];
	}

	dfs(0);

	printf("%d\n",max);

	return 0;
}
