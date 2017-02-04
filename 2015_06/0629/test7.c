#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int count;
void handler(int n)
{
	count++;
	printf("handler%d\n",n);

	if(count == 5)
	{
		printf("five\n");
	}
	else if(count == 7)
	{
		printf("7shou\n");
	}
	else if(count == 12)
	{
		printf("12\n");
	}
	alarm(1);
}


int main(int argc, char const *argv[])
{
	signal(SIGALRM,handler);
	
	alarm(1);

	getchar();
	getchar();

	return 0;

}

