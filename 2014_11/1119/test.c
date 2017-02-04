/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int tmp;
    char buf_1[100] = "hello";
    tmp = creat("kk",0755);

    if(tmp == -1)
    {
        printf("creat file error\n");
        perror("create file ");
    }

    printf("%d\n",tmp);
    int fd;
    if((fd = open("kk",O_RDWR | O_CREAT,0755)) == -1)
    {
        perror("open file error");
    }

    int write_num;

    if((write_num = write(fd,buf_1,strlen(buf_1))) == -1);
    {
        printf("write error !\n");
        perror("write file ");
    }

    printf("write num is %d\n",write_num);
    return 0;
}
