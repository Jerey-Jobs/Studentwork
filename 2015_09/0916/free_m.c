#include <stdio.h>

void func(char **p)
{
  **p = 'a';
}

int main()
{
	char *p = "hello";
	//free(p);
	//free(p);
	//*(p + 1) = 'a';
	func(&p);
	printf("%s",p);
}