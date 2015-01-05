/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name:   find_max.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/24
Description：找出2个字符串最长公共子串
Funcion List: 
             1.char *find_max(char *src,char *p)
*****************************************************/

#include <stdio.h>

/*找出src与p两个字符串中的最长公共子串，并返回该子串的指针*/
char *find_max(char *src,char *p)
{
    int max = 0;          //最长公共子串的长度
    int len;              //每个公共子串长度
    char *tmp = p;        //存放p指针
    char *begin;          //最长公共子串头指针
    char *start1;         //存放str当前比较位置
    char *start2;         //存放p当前比较位置

    /*先遍历主字符串*/
    while(*src != '\0')   
    {
        while(*p != '\0')
        {
            len = 0;      //每次比较len都置0
            start1 = src;      
            start2 = p;
            
            /*每次都遍历2个要比较的字符串*/
            while(*start1 != '\0' && *start2 != '\0')
            {
                
            /*当找到一个字符相同时，挨个接下去比较 直到出现不同*/
                if(*start1 == *start2)
                {
                    len++;           //记下长度
                    start1++;
                    start2++;
                }
                else break;
            }

            /*找出该次比较中最长的公共子串*/
            if(max < len)
            {
                max = len;
                begin = src;        //若该子串最长，记下子串起点
            }

            p++;
        }

        p = tmp;                    //p指针从新指向字符串开始,进行新一轮比较
       
        src++;
    }

    *(begin + max) = '\0';          //在最长公共子串的结尾加'\0'便于直接输出

    return begin;
}

int main()
{

    char str_1[100];                
    char str_2[100];
    char *start;                      //存放最长公共子串起始位置


    printf("input the string1:");
    scanf("%s",str_1);

    printf("input the string2:");
    scanf("%s",str_2);

    start = find_max(str_1,str_2);    //调用find_max找出起始位置

    printf("the max same string is:%s\n",start);

    return 0;
 }

