#include "stdio.h"
#include "stdlib.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "fcntl.h"
#include "string.h"

int main(int argc,char **argv)
{
    if(argc < 2)
    {
        printf("Can Not Find Any File!\n");
        exit(1);
    }

    int fd;
    int i = 1;

    while(argv[i] != NULL)
    {
        if((fd = open(argv[i++], O_RDONLY)) == -1)
            printf("Open File Error");


        char buf;

        while(read(fd,&buf,sizeof(char))!=0)
            printf("%c",buf);
    }

    close(fd);
    return 0;
}


