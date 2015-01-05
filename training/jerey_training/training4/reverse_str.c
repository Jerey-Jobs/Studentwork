/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：    reverse_str.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/17
Description：将一个字符串逆序
Funcion List: 
             1. int reverse(char *str)
*****************************************************/

#include <stdio.h>
#include <string.h>

/*************************************************
Function:       int reverse(char *str)
Description:    将该字符串逆序
Calls:          no
Called By:      main
Input:          str    被逆序的字符串
Return:         no
*************************************************/ 
int reverse(char *str)
{
    char *end = str + strlen(str) - 1;    //将end指向字符串'\0'前面一个字符
    char tmp;
    
    /*头尾掉换，直到str不小于end*/
    while(str < end)
    {
        tmp = *str;
        *str = *end;
        *end = tmp;
        str++;
        end--;
    }
}

int main()
{
    char str[100];                        //原子符串                    
    
    printf("please input string  :");
    scanf("%s",str);

    reverse(str);                         // 调用reverse函数实现倒序   

    printf("output str is :%s\n",str);
   
    return 0;
}
