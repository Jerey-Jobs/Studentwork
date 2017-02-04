#include <stdio.h>

int main(int argc, char const *argv[])
{
	*((int *)0x67a9) = 0xaa55;
	return 0;
}

