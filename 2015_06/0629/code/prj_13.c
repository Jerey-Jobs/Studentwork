/**
 * @author evan lau
 * @date 2015/06/15
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fd;
	char buf[1024];

	if(1 == argc)
	{
		printf("Please try again!\n");
		exit(0);
	}

	if((fd = open(argv[1], O_RDONLY)) == 0)
	{
		perror("open file error ");
		exit(0);
	}

	while(read(fd, buf, sizeof(buf)))
	{
    	printf("%s", buf);
	}

	close(fd);
	
	return 0;
}


