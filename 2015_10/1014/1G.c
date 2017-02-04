#include <stdio.h>
#include <fcntl.h>
#include "sys/stat.h"

int main(int argc, char const *argv[])
{
	int fd = open("file.txt",O_CREAT|O_RDWR,0777);
	lseek(fd,(1<<30),SEEK_END);
	write(fd,"0",1);
	return 0;
}

