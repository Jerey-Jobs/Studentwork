#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *p;
	p = "abcd";
	p[3] = 'f';
	printf("%s\n",p );	
	return 0;
}

