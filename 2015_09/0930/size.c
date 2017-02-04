#include <stdio.h>

struct a
{
	char a:1;
	char b:2;
	int e:3;
	int s:5;
	char c:1;
};

int main(int argc, char const *argv[])
{
	printf("%d\n", sizeof(struct a));
	printk("hello");

	return 0;
}

