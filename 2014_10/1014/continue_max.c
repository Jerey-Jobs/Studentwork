/*************************************************
Copyright (C), 1988-1999, Lighting Tech.Co., Ltd.
File name:  my_strcat
Author:  Jerey     Version: 0.2       Date: 2014/10/15
Descriptiostr:  找出输入的字符串中最长的连续数字子串，并输出该子串
Function List: 
              1.int my_strcpy(char *point, char *str, int len)
              2.int continue_max(char *str, char *output)                  
*************************************************/

#include <stdio.h>

/*************************************************
Function        int  my_strcat(char *point , char *str, int len)
Description:    实现str所指之后的len个字符的复制
Calls:          no
Called By:      int my_strcpy(char *point, char *str, int len)
Input:          point   目标字符串
                str     原字符串
                len     复制长度
Return:         no     
*************************************************/
int my_strcpy(char *point, char *str, int len)
{

/*str之后len个字符的复制*/
    while(len > 0)                 
    {
        *point = *str;          
        point++;                 
        str++;                   
        len--;                                 
    }
    *point = '\0';              

    return 0 ;
}
/*************************************************
Function:       int continue_max(char *str, char *output)
Description:    找出最长连续数字子串并调用my_strcpy函数将最长字串复制给output指向的字符串
Calls:          my_strcpy
Called By:      main
Input:          str     原字符串
                output  输出字符串  
Return:         int max 最长连续数字子串的长度
*************************************************/
int continue_max(char *str, char *output)
{ 
    int count = 0;               //数字子串长度
    int max = 0;                 //最长的数字子串长度

    while(*str != 0)
    {
        while(*str >= '0' && *str <= '9')       //判断该字符是否为数字
        {
            str++;
            count++;
        }

        /*找出最大的count并赋值给max,调用my_strcpy*/		
        if (count > max)        
        {
            max = count;
            my_strcpy(output, str - max, count); //str-max指针指向数字子串开始处
        }

        count = 0;                //count清0,重新计数
		
        str++;
    }

    return max;                   //返回最长数字子串长度
}


int main()
{
    char str[100];                //输入字符串
    char ptr[100];                //保存结果
    int tmp;                      

    printf("input a string: "); 
    scanf("%s", str);

    tmp = continue_max(str, ptr);              //调用continue_max 得到最长连续数字子串长度并拷贝进ptr

    printf("the max length = %d\n", tmp);     //输出最长数字子串长度
    printf("the max string = %s\n", ptr);     //输出最长数字字串 
	
    return 0;
}
