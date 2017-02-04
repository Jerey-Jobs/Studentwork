#include <stdio.h>

#define Max(a,b) ((a)>(b)?(a):(b))

int main(int argc, char const *argv[])
{
	unsigned char a = 0xA5;
	unsigned char b = ~a>>4+1;

	printf("%d\n", b);

	printf("%d\n", sizeof a);
	return 0;
}