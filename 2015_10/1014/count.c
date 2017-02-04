#include <stdio.h>

int count;
int num[] = {1,2,5,10};
void myfunc(int n,int k)
{
	if(n < 0 )return;
	if(n == 0)
	{
		count++;
		return;
	}
	int i;

	for(i = k; i < 4; i++)
	{	
	   	myfunc(n - num[i],i);
	}
}

int main(int argc, char const *argv[])
{
	myfunc(3,0);
	printf("%d\n", count);	
	return 0;
}

