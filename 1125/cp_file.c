/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    FILE *fd;
    FILE *w_fd;

    char r_buf[100];

    fd = fopen("a.txt","a+");

    w_fd = fopen("b.txt","a+");

    while(fgets(r_buf,sizeof(r_buf),fd) != NULL)
    {
        fputs(r_buf,w_fd);
        memset(r_buf,0,sizeof(r_buf));
    }
 
    printf("cp ok!\n");

    fclose(w_fd);
    return 0;
}
