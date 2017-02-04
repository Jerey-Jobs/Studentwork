#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char str[10],ptr[10];

	int i;
	for(i = 0; i < 10; i++)
	{
		ptr[i] = 'a';
	}
	strcpy(str,ptr);

	printf("%s\n",str );
		
	return 0;

}

