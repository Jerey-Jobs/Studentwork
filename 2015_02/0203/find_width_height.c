#include <stdio.h>
#include <string.h>

int a[1000][2],s[1000];
int i,n,x,y; 

void dfs(int i,int k)
{
	s[k]=s[k]+1;

	if(k>x)
	{	
		x=k;
	}

	if(a[i][0]!=0)
	{	
		dfs(a[i][0], k+1);
	}

	if(a[i][1]!=0)	
	{
		dfs(a[i][1], k+1);
	}
}

int main()
{
	scanf("%d",&n);

	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	
	for(i = 0; i < n; i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
	}

	x=0;
	dfs(0,0);
	y=0;

	for(i=0;i<1000;i++)
	{	
		if(s[i] > y)
		{	
			y=s[i];
		}
	}

	printf("%d %d\n", y, x + 1);
	
	return 0;
}
