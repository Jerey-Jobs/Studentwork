/*************************************************
 Copyright (C), 1988-1999, Lighting Tech.Co., Ltd.
 File name:   int2str.c
 Author:  Jerey     Version: 0.1       Date: 2014/10/14
 Description:    输入一个整型n转换为字符串输出  
 Function List:  char *intstr(int n)
 **************************************************/

#include<stdio.h>
/*************************************************
Function:       char *intstr(int n)
Description:    将整型n转换为一个字符串，并返回该字符串的指针str 
Calls:          no
Called By:      main
Input:          int n   输入整型
Return:         char *str 返回字符串的指针
*************************************************/ 
char *intstr(int n)
{
    static char str[32];                //存放结果
    char *point = str;
    int tmp;                            
    int len = 0;                        //字符长度                      
    int i;                              

    /*eg: 123 % 10 = 3 ; '3' = 3 + '0'*/
    while (n > 0)                   
    {
        tmp = n % 10;
        *point = tmp + '0';         
        n = n / 10;
        point++;                        
        len++;                        
    }
	
    *point = '\0';          
	
    /*对字符串逆序，首尾掉换 '\0' 除外*/
    for (i = 0; i < (len - 1) / 2; i++)       
    {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }

    return str;                          //将字符数组指针str返回
}
int main()
{
    int num;                             //待转变整型      

    printf("input a number :");
    scanf("%d",&num);
	
    printf("output string is : %s\n", intstr(num));  //调用intstr函数，将整型转成字符串输出
	
    return 0;
}
