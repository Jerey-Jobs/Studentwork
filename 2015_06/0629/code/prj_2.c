/**
 * @author evan lau
 * @date 2015/06/13
 */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define FILE_PATH "./a.txt"
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
	int fd;    /* File descriptor */
    char buffer[BUFFER_SIZE];

	fd = open(FILE_PATH, O_RDWR | O_CREAT, 0744);
    if (fd < 0)
	{
        perror("Open file error:");
		exit(0);
	}
	
	gets(buffer);
	write(fd, buffer, strlen(buffer));

	close(fd);
	
    return 0;
}
