/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   check_putin.c
Author：Jerey_Jobs    Version:0.1    Date: 
Description：检测用户输入，并调用该功能的函数
Funcion List: int check_putin(LINK *head)
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:       int check_putin(LINK *head)
Description:    检测用户输入的指令，并执行该功能函数
Calls:     

Called By:  menu(LINK *head)    
Input:      
Return:     NO    
*************************************************/ 
int my_check_putin()
{
    char check[MAX];
    
    setbuf(stdin,NULL);                        //清空输入缓冲

    printf("\t\t\033[47;31m请输入指令:\033[0m   ");

    gets(check);                               //读入输入的命令

    if(my_strcmp(check,"log") == 0)            //若输入的为ADD 则调用my_add增加一个联系人
    {
        return LOG;
    }

    else if(my_strcmp(check,"regist") == 0)   //若输入为DISPLAY 调用my_display函数
    {
        return REGIST;
    }

    else if(my_strcmp(check,"show") == 0)    //若输入为DELETE 调用my_delete函数
    {
        return SHOW;
    }

    else if(my_strcmp(check,"chat") == 0)    //若输入为SEARCH 调用my_search函数 
    {
        return CHAT;
    }

    else if(my_strcmp(check,"broad") == 0)    //若输入为SEARCH 调用my_search函数 
    {
        return BROAD;
    }

    else if(my_strcmp(check,"hi") == 0)    //若输入为SEARCH 调用my_search函数 
    {
        return HI;
    }

    else if(my_strcmp(check,"cpwd") == 0)    //若输入为SEARCH 调用my_search函数 
    {
        return CPWD;
    }

    else if(my_strcmp(check,"rname") == 0)    //若输入为SEARCH 调用my_search函数 
    {
        return RNAME;
    }

    else if(my_strcmp(check,"logoff") == 0)    //若输入为SEARCH 调用my_search函数 
    {
        return LOGOFF;
    }

    else if(my_strcmp(check,"exit") == 0)      //若输入为QUIT 程序退出
    {
        return EXIT; 
    }

    else if(my_strcmp(check,"kick") == 0)      //若输入为QUIT 程序退出
    {
        return KICK; 
    }

    else if(my_strcmp(check,"ban") == 0)      //若输入为QUIT 程序退出
    {
        return BAN; 
    }
    else if(my_strcmp(check,"rid") == 0)      //若输入为QUIT 程序退出
    {
        return RID_PEOPLE; 
    }

    /*若错误输入 则继续调用menu函数 提示错误并重新输入*/
    else
    {
        printf("\t\t\033[47;31m输入错误，请重新输入!\033[0m");

  //      getchar();
        scanf("%*[^\n]");
        system("clear");
        
    }

    return 0;

}
