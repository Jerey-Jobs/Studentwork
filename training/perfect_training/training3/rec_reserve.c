/****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：  training3_4.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/22
Description： 利用递归函数调用方式,将所输入的n个字符以相反顺序打印出来
Funcion List: 
             1.int my_printf(char *p,int len)
*****************************************************/

#include <stdio.h>
#include <string.h>

/*************************************************
Function:       int my_printf(char *p,int len)
Description:    递归的方法逆序输出p字符串
Calls:          no
Called By:      main
Input:          char *p    目标字符串
                int len    目标字符串长度
Return:         no
*************************************************/ 
int my_printf(char *p,int len)
{
    if(len >= 0)
    {
        printf("%c",*(p + len ));    //输出最后一位
       
        my_printf(p,len-1);          //继续调用该函数输出前一位
    }

    return 1;
}

int main()
{
    char str[100];            //待逆序字符串
    int len ;                 //字符串长度

    printf("please input string :");
    scanf("%s",str);

    len= strlen(str);

    printf("reserve string is:");
    
    my_printf(str,len);       //调用my_printf逆序打印该字符串
    
    printf("\n");


    return 0;
}
