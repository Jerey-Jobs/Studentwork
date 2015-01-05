/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：     printf_head_tail.c
Author：Jerey_Jobs    Version:0.1    Date:2014/10/18
Description：   输入一个字符串,同时输入帧头和帧尾(可以是多个字符)
                将该字符串中合法的帧识别出来.
Funcion List: 
             1.int output_useful(char *str, char *head, char *tail)
             2.int my_strcmp(char *point, char *src)
*****************************************************/

#include <stdio.h>
#include <string.h>

/*************************************************
Function:       int my_strcmp(char *point, char *src)
Description:    比较point处之后与src等长的字符串是否与src相同，若相同返回1 不同返回0
Calls:          no
Called By:      int output_useful(char *str, char *head, char *tail)
Input:          char *point   待比较的目标字符串
                char *src     源字符串
Return:         0  若不同返回0 
                1  若相同返回1
*************************************************/ 
int my_strcmp(char *point, char *src)
{
    int len;                          //src长度
    int i;

    len = strlen(src);
    
    /*若point后面len长度内有与src不一样的，则子函数结束 返回0*/
    for(i = 0; i < len; i++)
    {
        if(*point != *src)
        {
            return 0;
        }
        point++;
        src++;
    }

    return 1;                         //若一直不存在不一样的，则返回1
}

/*************************************************
Function:       int output_useful(char *str, char *head, char *tail)
Description:    找出str中帧头至帧尾的有效部分 并输出 
Calls:          int my_strcmp(char *point, char *src)
Called By:      main
Input:          char *str     主字符串指针
                char *head    帧头指针
                char *tail    帧尾指针
Output:         char *start   字符串中有效部分
Return:         no
*************************************************/ 
int output_useful(char *str, char *head, char *tail)
{
    int tmp;
    char *start;                         //存放帧头位置
    
    /*遍历字符串，找到帧头并将地址赋值给 start*/
    while(*str != '\0')
    {
        tmp = my_strcmp(str, head);      //调用my_strcmp 挨个与帧头比较 若为帧头tmp ＝ 1 
        
        if(tmp == 1)                     
        {
            start = str;                 //存放帧头地址
        }

        str++;
    }

    str = start + strlen(head);          //将指针指回帧头结束处

    
    /*继续遍历字符串，找到帧尾并在帧尾加上 '\0' */
    while(*str != '\0')
    {
        tmp = my_strcmp(str, tail);      //调用my_strcmp 挨个与帧尾相比较 若相同则返回1

        if(tmp == 1)
        {
            *(str + strlen(tail)) = '\0';//在帧尾结束加'\0'   
        }

        str++;
    }

    printf("output : %s\n",start);       //输出有效部分    

}

int main()
{
    char str[100];                    //总字符串
    char head[100];                   //帧头
    char tail[100];                   //帧尾

    printf("input string :");
    scanf("%s",str);

    printf("input head :");
    scanf("%s",head);

    printf("input tail :");
    scanf("%s",tail);
 
    output_useful(str,head,tail);     //调用ouput_useful 输出字符串中有效部分


    return 0;
}
