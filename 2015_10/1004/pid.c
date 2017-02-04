#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;

	for(i = 0; i < 2; i++)
	{
		fork();
		printf("ppid = %d | pid = %d |i = %d \n",getppid(),getpid(),i );
	}
	sleep(10);

	return 0;
}

