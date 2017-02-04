#include <stdio.h>
#include <stdlib.h>

void fun(int **a)
{
	printf("%p\n",a );
//	printf("%p\n",a[1]);
	// printf("%p %d\n", &a[0][0],a[0][0]);
	// printf("%p %d\n", &a[0][1],a[0][1]);
	// printf("%p %d\n", &a[1][0],a[1][0]);
	// printf("%p %d\n", &a[1][1],a[1][1]);

	printf("%d\n",a[0][1] );
}


int main(int argc, char const *argv[])
{
	int a[2][2];
	a[0][1] = 1;

	int **p = (int **)malloc(sizeof(2*2));

	p[0] = a[0];
	p[1] = a[1];

	// 	printf("%p %d\n", &a[0][0],a[0][0]);
	// printf("%p %d\n", &a[0][1],a[0][1]);
	// printf("%p %d\n", &a[1][0],a[1][0]);
	// printf("%p %d\n", &a[1][1],a[1][1]);
	// printf(" \n");
	

	fun(p);
	

	return 0;
}

