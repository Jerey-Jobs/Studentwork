/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：      main.c
Author：Jerey_Jobs    Version:0.1    Date: 2014.11.23
Description： 停车场系统主函数
Funcion List: void create_stack()
              void menu()  
*****************************************************/

#include "../../include/myhead.h"

int main()
{
    int fd;

    if((fd = open("park_infomation",O_CREAT | O_RDWR,0755)) == -1)
    {
        perror("open file error");
    }
    
    lseek(fd,0,SEEK_END);

    create_stack();          //初始化栈、队列

    menu(fd);                  //调用主界面函数

    return 0;
}
