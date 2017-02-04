#include <stdio.h>

int main(int argc, char const *argv[])
{
 //   *((void *)())0x1000();
	((void(*)(void))0x1000)();
	return 0;

	
}