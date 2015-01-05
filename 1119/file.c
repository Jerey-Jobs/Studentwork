#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int fd;
    int w_count = 0;
    int r_count = 0;

    char w_buf[100] = "hello world";
    char r_buf[100];

    if((fd = creat("a.c",0755)) == -1)
    {
         printf("creat error:%s\n",strerror(errno));
	// perror("creat error");
	 exit(1);
    }//

    
    if((fd = open("b.c",O_CREAT | O_RDWR,0755)) == -1)
    {
         perror("open file error");
    }

    if((w_count = write(fd,w_buf,strlen(w_buf))) == -1)
    {
         perror("write file error");
    }

    printf("w_count = %d\n",w_count);

    lseek(fd,0,SEEK_SET);

    if((r_count = read(fd,r_buf,w_count)) == -1)
    {
        perror("read file error");
    }
     
    printf("read count:%d read data:%s\n",r_count,r_buf);

    close(fd);

    return 0;
}
