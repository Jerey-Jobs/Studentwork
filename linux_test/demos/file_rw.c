#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <errno.h>

#define MAX 1024

enum COM{PARAM_ERROR,OPEN_ERROR,WRITE_ERROR,READ_ERROR};

int write_line(int fd, char *buf, int len)
{
     int w_count;

     if((w_count = write(fd,buf,len)) == -1)
     {
         perror("write error!");
	 exit(WRITE_ERROR);
     }

     write(fd,"\n",1);
}

int read_line(int fd, char *buf, int len)
{
     int i;
     char temp;
     
     for(i = 0; i < len; i++)
     {
          if(read(fd,&temp,1) < 0)
	  {
	      perror("read error");
	      exit(READ_ERROR);
	  }

	  if(temp == '\n')
	  {
	      buf[i] = '\0';
	      return i;
	  }

	  buf[i] = temp;
     }

     buf[i] = '\0';

     return len;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Please input one param!\n");
	exit(PARAM_ERROR);
    }
    
    int n;
    int i;
    int fd;

    char w_buf[MAX];
    char r_buf[MAX];

    if((fd = open(argv[1],O_CREAT | O_RDWR,0655)) == -1)
    {
        perror("open file error");
	exit(OPEN_ERROR);
    }

    printf("Please input line number:");
    scanf("%d",&n);

    getchar();
    
    for(i = 0; i < n; i++)
    { 
	memset(w_buf,0,sizeof(w_buf));
	printf("Please input line data:\n");
	gets(w_buf);

	write_line(fd,w_buf,strlen(w_buf));
    }
    
    lseek(fd,0,SEEK_SET);

    for(i = 0; i < n; i++)
    {
        memset(r_buf,0,sizeof(r_buf));

	read_line(fd,r_buf,MAX);

	printf("line %d data:%s\n",i,r_buf);
    }

    return 0;
}
