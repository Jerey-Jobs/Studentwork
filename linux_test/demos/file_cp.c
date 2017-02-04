#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc,char **argv)
{

	int from_fd,to_fd;
	int bytes_read,bytes_write;
	char buffer[BUFFER_SIZE];
	char *ptr;

	if(argc!=3)
	{
		fprintf(stderr,"Usage:%s fromfile tofile/n/a",argv[0]);
		exit(1);
	}

	/* ´ò¿ªÔ´ÎÄ¼þ */

	if((from_fd=open(argv[1],O_RDONLY))==-1)
	{
		fprintf(stderr,"Open %s Error:%s/n",argv[1],strerror(errno));
		exit(1);
	}

	/* ´´½¨Ä¿µÄÎÄ¼þ */

	if((to_fd=open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1)
	{
		fprintf(stderr,"Open %s Error:%s/n",argv[2],strerror(errno));
		exit(1);
	}

	/* ÒÔÏÂ´úÂëÊÇÒ»¸ö¾­µäµÄ¿½±´ÎÄ¼þµÄ´úÂë */

	while(bytes_read=read(from_fd,buffer,BUFFER_SIZE))
	{
		/* Ò»¸öÖÂÃüµÄ´íÎó·¢ÉúÁË */
		if((bytes_read==-1)&&(errno!=EINTR)) break;
		else if(bytes_read>0)
		{
			ptr=buffer;
			while(bytes_write=write(to_fd,ptr,bytes_read))
			{
				/* Ò»íÎó·¢ÉúÁË */
				if((bytes_write==-1)&&(errno!=EINTR))break;
				/* Ð´ÍêÁËËùÓÐ¶ÁµÄ×Ö½Ú */
				else if(bytes_write==bytes_read) break;
				/* Ö»Ð´ÁËÒ»²¿·Ö,¼ÌÐøÐ´ */
				else if(bytes_write>0)
				{
					ptr+=bytes_write;
					bytes_read-=bytes_write;
				}
			}
			/* Ð´µÄÊ±ºò·¢ÉúµÄÖÂÃü´íÎó */
			if(bytes_write==-1)break;

		}
	}
	close(from_fd);
	close(to_fd);
	exit(0);
}
