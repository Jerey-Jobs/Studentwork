/**
 * @author evan lau
 * @date 2015/06/15
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
	int i = 0;
    int src_fd;
    int des_fd;
    int line_num = 0;
    char file_path[64];
    char buf[1024];

    if(1 == argc)
    {
    	printf("Usage error, please try again!\n");
    	exit(0);
    }

	/**
	 * change file name to tmp_$src_filename.
	 */
    sprintf(file_path, "tmp_%s", argv[1]);

	/**
	 * Open source file.
	 */
    if((src_fd = open(argv[1], O_RDONLY)) == 0)
    {
	    perror("open file error: ");
    	exit(0);
    }

	/**
	 * Open (or create if not exist) 
	 */
    if((des_fd = open(file_path, O_WRONLY | O_CREAT, 0666)) == 0)
    {
    	perror("create file error: ");
	    exit(0);
    }

	sprintf(buf, "%d.", line_num);
	i = strlen(buf) - 1;
    while(1)
    {
		/**
		 * Read one charactor from source file.
		 */
        if(read(src_fd, &buf[i], 1) == 0)
		{
            break;
		}

		/**
		 * End of a line.
		 */
		if(buf[i] == '\n')
		{
			sprintf(buf, "%s\n", buf);
            write(des_fd, buf, i + 1);
			line_num++;
			sprintf(buf, "%d.", line_num);
			i = strlen(buf) - 1;
		}
		i++;
    }

    close(src_fd);
    close(des_fd);
	
    return 0;
}



