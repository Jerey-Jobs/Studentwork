#include "stdio.h"
int count;
int buff[4] = {1,2,5,10};
void func2(int n,int k,int m)
{
	if(n == m)
	{
		count++;
		return ;
	}
		else if(n > m)
		return ;
	int i = 0;
	for(i = k; i < 4; i++)
	{
		func2(n+buff[i],i,m);
	}
}


int main()
{
	func2(0,0,10);
	printf("%d\n",count);
}