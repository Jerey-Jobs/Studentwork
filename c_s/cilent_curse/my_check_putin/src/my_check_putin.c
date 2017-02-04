/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   check_putin.c
Author：Jerey_Jobs    Version:0.1    Date: 
Description：  检测用户输入，并返回相应的宏定义
Funcion List: int check_putin()
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:       int check_putin()
Description:    检测用户输入的指令，并执行该功能函数
Calls:      NO
Called By:  main    
Input:      NO
Return:         
*************************************************/ 
int my_check_putin()
{
    char check[MAX];
    
    setbuf(stdin,NULL);                        //清空输入缓冲
    printf("\t\t\t\t\033[47;31m请输入指令:\033[0m");

    my_getns(check,MAX);                               //读入输入的命令

    if(my_strcmp(check,"log") == 0)           //若输入为log 则返回LOG 宏定义
    {
        return LOG;
    }

    else if(my_strcmp(check,"regist") == 0)  
    {
        return REGIST;
    }

    else if(my_strcmp(check,"show") == 0)    
    {
        return SHOW;
    }

    else if(my_strcmp(check,"chat") == 0)   
    {
        return CHAT;
    }

    else if(my_strcmp(check,"broad") == 0)    
    {
        return BROAD;
    }

    else if(my_strcmp(check,"hi") == 0)   
    {
        return HI;
    }

    else if(my_strcmp(check,"cpwd") == 0)   
    {
        return CPWD;
    }

    else if(my_strcmp(check,"rname") == 0)   
    {
        return RNAME;
    }

    else if(my_strcmp(check,"logoff") == 0)   
    {
        return LOGOFF;
    }

    else if(my_strcmp(check,"exit") == 0)     
    {
        return EXIT; 
    }

    else if(my_strcmp(check,"kick") == 0)    
    {
        return KICK; 
    }

    else if(my_strcmp(check,"ban") == 0)      
    {
        return BAN; 
    }
    else if(my_strcmp(check,"rid") == 0)     
    {
        return RID_PEOPLE; 
    }

    /*若错误输入 则继续调用menu函数 提示错误并重新输入*/
    else
    {
    printf("\t\t\t\t\033[47;31m输入错误，请重新输入!\033[0m");

        scanf("%*[^\n]");                     //清空输入缓冲
        system("clear");
        
    }

    return 0;

}
