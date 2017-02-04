#include <stdio.h>

int book[100];
int result[100][100];
int a[100];
int k[100];
int n;
int count;

void dfs(int step)
{
	int i;
	int sum = 0;

	for(i = 0; i < n; i++)
	{
		sum += k[i]*a[i];
	}
	if(sum == 1000)
	{
       
        for(i = 0; i < n; i++)
        {
        	result[count][i] = k[i];
        }
         count++;
       // return;
	}

	if(step >= n)
	{
		return;
	}

	for(i = 0; i < 1000; i++)
	{
      	if(book[i] == 0)
		{
			book[i] = 1;
		    k[step] = i;
		    dfs(step + 1);
            book[i] = 0;
		}
	}

}


int main(int argc, char *argv[])
{
	int i;
	int j;
	scanf("%d",&n);

	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}

	dfs(0);

	for(i = 0; i < count; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}


	return 0;
}


