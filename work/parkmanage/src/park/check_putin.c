/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   check_putin.c
Author：Jerey_Jobs    Version:0.1    Date: 2014.11.23
Description：检测用户输入，并调用该功能的函数
Funcion List: int check_putin()
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:       int check_putin()
Description:    检测用户输入的指令，并执行该功能函数
Calls:          int add_car()
                int get_car()
                int display_park()
                void menu()
Called By:      void menu()    
Input:          NO
Return:         NO    
*************************************************/ 
int check_putin()
{
    char check[MAX];
    
    setbuf(stdin,NULL);                        //清空输入缓冲

    printf("\t\t\033[47;31mplease input conmand:\033[0m   ");

    gets(check);                               //读入输入的命令

    if(my_strcmp(check,"1") == 0)              //若输入的为3 则调用add_car
    {
        add_car();
    }

    else if(my_strcmp(check,"2") == 0)         //若输入为2 调用get_car函数
    {
        get_car();
    }

    else if(my_strcmp(check,"3") == 0)         //若输入为3 调用display_park函数
    {
        display_park();
    }
    
    else if(my_strcmp(check,"4") == 0)         //若输入为4 程序退出
    {
        write_to_file();
        system("clear");
        printf("\n");
        printf("\t\t\tTHANKS FOR USEING!\n");

        getchar();
        system("clear");
        exit(1);
    }

    /*若错误输入 则继续调用menu函数 提示错误并重新输入*/
    else
    {
        printf("\t\t\033[47;31m输入错误，请重新输入!\033[0m");

        scanf("%*[^\n]");
        system("clear");
        
        menu();
    }


}
