#include <stdio.h>

int main(int argc, char const *argv[])
{
	char p1[] = "abcd";
	char p2[] = "ABCD";
	char str[50] = "xyz";
	strcpy(str+2,strcat(p1+2,p2+1));
	printf("%s\n",str );
	return 0;
}

