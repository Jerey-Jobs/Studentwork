/**
 * @author evan lau
 * @date 2015/06/13
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define PATH_LENGTH 256

void my_ls(char *dirname)
{
    DIR *dir_p;               /* dir pointer */
    struct dirent *dirent_p;  /* directory entry */
	char full_path[PATH_LENGTH];
	int dir_len = 0;

	if ((dir_p = opendir(dirname)) == NULL)
	{
		fprintf(stderr, "my_ls: cannot open %s\n", dirname);
	}

	/**
     * ^_^
     */
	while ((dirent_p = readdir(dir_p)) != NULL)
	{
		strcpy(full_path, dirent_p->d_name);

		printf("%s    ", full_path);
    }

	printf("\n");
	
	closedir(dir_p);
}


int main(int argc, char **argv)
{
	if (1 == argc)
	{
		my_ls("./");
	}
	else
	{
		while(--argc)
		{
			my_ls(*++argv);
		}
	}
	
    return 0;
}


