#include "stdio.h"

int book[10];
int a[10][10];
int n;
int sum = 0;

int dfs(int t)
{
    int i;
    printf("%d ",t);
    sum++;
    if(sum == n)
    {
    	return 0;
    }

    for(i = 1; i <= n; i++)
    {
    	if(a[t][i] == 1 && book[i] == 0)
    	{
    		book[i] = 1;
    		dfs(i);
    	}
    }

    return 0;

}

int main(int argc, char const *argv[])
{
	int i;
	int j;
	int left,right;

	scanf("%d",&n);

    for(i = 1; i <= n; i++)
    {
    	scanf("%d%d",&left,&right);
    	a[left][right] = 1;
    	a[right][left] = 1;
    }

    book[1] = 1;
    
    dfs(1);

    getchar(); 
    getchar(); 

	return 0;
}



