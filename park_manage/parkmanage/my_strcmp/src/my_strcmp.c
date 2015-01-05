/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：  my_strcmp.c
Author：Jerey_Jobs    Version:0.1    Date: 
Description：比较函数，若src与ptr相同 则返回0
Funcion List: no
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:       int my_strcmp(char *src,char *ptr)
Description:    比较两个输入的字符串是否与ptr相同
Calls:          no
Called By:      int check_putin(LINK *head)
Input:          char *src
                char *ptr
Return:         0 两个字符串相等
                -1 不相等
*************************************************/ 
int my_strcmp(char *src,char *ptr)
{
    if(src == NULL && ptr == NULL)
    {
        return 0;
    }

    /*遍历ptr 若src前面对应的src*/
    while(*ptr && *src && *ptr == *src)       
    {
        src++;
        ptr++;
    }
   
    return *src - *ptr;
}    

