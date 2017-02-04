#include <stdio.h>

void fun(int a[])
{
	printf("%d\n",sizeof(*a) );
}

int main(int argc, char const *argv[])
{
//	char *str = "hello";
	int a[5];
	fun(a);

//	printf("%d\n", strlen(str));

	
	return 0;
}
