#include "stdio.h"

void hanoi(char src,char mid,char dst,int n)
{
	if(n == 0)
	{
		return;
	}
	else
	{
		hanoi(src,dst,mid,n-1);
		printf("Move %d from %c to %c\n", n,src,dst);
		hanoi(mid,src,dst,n-1);
	}

}


int main(int argc, char const *argv[])
{
	int n;

	printf("input n:\n");
	scanf("%d",&n);

	hanoi('a','b','c',n);

	return 0;
}


