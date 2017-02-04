#include <stdio.h>

char *func()
{
	char *p = (char *)malloc(100);
	strcpy(p,"hello");
	return p;
}



int main(int argc, char const *argv[])
{
	char *str;

	str = func();

	char *q = (char *)malloc(100);
	strcpy(q,"wwwwwwwwwwwwww");

	printf("%s\n",str);
	return 0;
}

