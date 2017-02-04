#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	/* code */
	int fd;

	fd = open("hhh",O_CREAT|O_RDWR,0777);

	printf("%d\n",close(fd) ); 
	printf("%d\n",close(fd) ); 


	return 0;
}