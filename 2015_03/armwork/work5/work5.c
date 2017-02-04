#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
	FILE * fp;
	int num;
	int folder;

	char a[] = "hello ARM Linux!";

	fp = fopen("/tmp/linux.txt" , "w+");

	if(NULL == fp)
	{
		perror("Fail to open linux.txt!");
		exit(-1);
	}

	num = fwrite(a, sizeof(a), 1, fp);
	printf("%d byte data has written to linux.txt\n", num * sizeof(a));

	folder = mkdir("/tmp/linux", 1);

	if(-1 == folder)
	{
		printf("\nFail to create folder linux!\nIt has exiated or the path is error!\n");
		exit(-1);
	}

	printf("Folder linux created success!\n");

	close(fp);
	return 0;
}



