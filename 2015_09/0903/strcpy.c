#include <stdio.h>

char *my_strcpy(char *str,const char *ptr)
{
	if(str == NULL || ptr == NULL)
	{
		return 0;
	}

	char *address = str;

	while((*str++ = *ptr++) != '\0');

	return address;
}


int main(int argc, char const *argv[])
{
	char a[] = "hello";
	char b[] = "wwwww";

	my_strcpy(a,b);
	printf("%s\n", a);
	return 0;
}

