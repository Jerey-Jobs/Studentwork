#include <stdio.h>
#include <string.h>

#define SWAP(a,b) (a)^=(b);(b)^=(a);(a)^=(b)

void Reverse(char *a)
{
	char *head = a;
	char *tail = a;
	//tail = head + strlen(a) -1;
	while(head < tail)
	{
		SWAP(*head,*tail);
		head++;
		tail--;
	}
}

int main(int argc, char const *argv[])
{
	char a[] = "hello";

	Reverse(a);

	printf("%s\n", a);

	int c = 2;
	int d = 4;
	SWAP(c,d);
	printf("%d %d\n",c,d );
	return 0;
}