/**
 * @author evan lau
 * @date 2015/06/13
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    execl("/bin/ls", "ls", "-l", NULL);
	
	return 0;
}

