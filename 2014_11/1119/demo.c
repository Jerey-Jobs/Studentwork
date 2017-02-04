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

int main(int argc,char *argv[])
{
    int write_num[3];
    int read_num;
    char str[100];
    char read_buf[100];

    printf("please input \n");
    
    int fd;
   
    if((fd = open(argv[1],O_CREAT | O_RDWR,0755)) == -1)
    {
        perror("open file error");
    }

    int i;
    for(i = 0; i < 3; i++)
    {
        memset(str,0,strlen(str));

        gets(str);
    
        if((write_num[i] = write(fd,str,strlen(str))) == -1)
        {
            perror("write error");
        }
    }

    lseek(fd,0,SEEK_SET);

    for(i = 0; i < 3; i++)
    {
        memset(read_buf,0,strlen(read_buf));

        if((read_num = read(fd,read_buf,write_num[i])) == -1)
        {
            perror("read error ");
        }
        
        printf("%d:%s\n",i,read_buf);
    }

    return 0;
}
