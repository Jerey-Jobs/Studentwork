#include <stdio.h>

void HanNuo(int a,int b,int c,int step)
{
	if(0 == step)
	{
		return;
	}
	else
	{
		HanNuo(a,c,b,step - 1);
		printf("Move %d from %c to %c\n", step,a,c);
		HanNuo(b,a,c,step - 1);
	}
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);

	HanNuo('a','b','c',n);	
	return 0;
}

