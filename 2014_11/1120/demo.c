/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define MAX 100

int read_line(int fd,char *buff,int len)
{
    int i;
    char temp;

    for(i = 0; i < len; i++)
    {
        if(read(fd,&temp,1) == -1)
        {
            perror("read error");
        }

        if(temp == '\n')
        {
            buff[i] = '\0';
            return i;
        }

        buff[i] = temp;
    }

    *buff = '\0';
    return len;
}

int write_line(int fd,char *buf,int len)
{
    int tmp;

    if((tmp = write(fd,buf,strlen(buf))) == -1)
    {
        perror("write error");
        exit(1);
    }

    write(fd,"\n",1);
}

int main(int argc,char *argv[])
{
    char w_buf[MAX];                //存放输入缓冲区
    char r_buf[MAX];
    int fd;                         //文件描述符

    /*创建文件并打开*/
    if((fd = open(argv[1],O_CREAT | O_RDWR,0755)) == -1)
    {
        perror("open file error");
    }

    int i;
    int n;

    printf("please input line number:");
    scanf("%d",&n);

    getchar();

    /*3行数据依次存入文件中*/
    for(i = 0; i < n; i++)
    {
        memset(w_buf,0,sizeof(w_buf));

        gets(w_buf);

        write_line(fd,w_buf,strlen(w_buf));
    
    }

    lseek(fd,0,SEEK_SET);           //文件指针移动到文件头

    for(i = 0; i < n; i++)
    {
        memset(r_buf,0,sizeof(r_buf));

        read_line(fd,r_buf,MAX);

        printf("the %d line : %s\n",i + 1,r_buf);
    }

    return 0;
}
