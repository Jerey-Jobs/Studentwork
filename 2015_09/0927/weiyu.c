#include <stdio.h>

int f(int x,int y)
{
	printf("%d\n",(x&y) );
	printf("%d\n",((x^y)>>1 ));
	return (x&y) + ((x^y)>>1);
}

int main(int argc, char const *argv[])
{
	printf("%d\n", f(10,15));	
	return 0;
}
