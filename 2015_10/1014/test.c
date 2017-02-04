#include <stdio.h>

int main(int argc, char const *argv[])
{
	char s[] = "hello";

	printf("%d\n",sizeof(s) );	
	printf("%d\n", strlen(s));
	return 0;
}

