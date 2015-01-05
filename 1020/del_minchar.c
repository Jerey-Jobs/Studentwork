/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：  del_minchar.c
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

/*将src字符串中所有acbd到z出现的次数 存入count数组相应的元素中*/
int num_ofa_z(char *src,int *count)
{
    while(*src != '\0')  
    {
        *(count + (*src - 'a') ) += 1;     //sp: a存于count[0]; 0 = 'a' - 'a'
        src++;
    }
}

/*找出count数组中最小的非0数,并返回最小值*/
int find_min(int *count)
{
    int min;
    int i;

    for(i = 0; i < 26; i++)               //将数组中第一个非0数赋值给min
    {
        if(*(count + i) != 0)                  
        {
            min = *(count + i);           
        }
    }

    /*找出count中最小非0数*/
    for(i = 0; i < 26; i++)
    {
        if(min > *(count + i) && *(count + i) != 0)
        {
            min = *(count + i);
        }
    }

    return min;                         
}

/*把src中出现次数大于min的字母复制到ptr中*/
int del_minchar(char *src,int *count,int min,char *ptr)
{
    while(*src != '\0')                       
    {
        /*判断src所指字符是否是大于次数最小的 若大于则复制*/
        if(*(count + (*src - 'a')) > min)   
        {
            *ptr = *src;
            *ptr++;
        }
        *src++;
    }

    *ptr = '\0';                    //ptr结尾加字符串结束标志

}   

int main()
{
    char src[100];                  //待输入字符串
    int count[26] = {0};            //存放26个字母出现次数
    char result[100];               //存放结果
    int min;

    printf("please input string : ");
    scanf("%s",src);

    num_ofa_z(src,count);               //调用num_ofa_z函数将src中26个字母的出现次数存入count相对应的元素中

    min = find_min(count);              //调用find_min 找出26字母中出现最少的次数

    del_minchar(src,count,min,result);  //调用del_minchar 将src中出现次数大于min的字母复制进result

    printf("output string is :%s\n",result);

    return 0;
}
