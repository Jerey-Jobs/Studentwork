/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：    train4_4.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/18
Description：  实现将”I am from shanghai ”倒置为”shanghai from am I”
               即将句子中的单词位置倒置,而不改变单词内部结构.
Funcion List: 
             1.int reverse(char *head, char *tail)
             2.int reverse_str(char *str)
*****************************************************/

#include <stdio.h>
#include <string.h>
/*************************************************
Function:       int reverse(char *head, char *tail)
Description:    将头尾指针之间的字符串逆序
Calls:          no
Called By:      int reverse_str(char *str)
Input:          char *head    
                char *tail
Return:         no 
*************************************************/ 

int reverse(char *head, char *tail)
{
    char tmp;

    while(head < tail)              //首尾掉换，直到head不小于tail止
    {
        tmp = *head;
        *head = *tail;
        *tail = tmp;
        head++;
        tail--;
    }

}


/*************************************************
Function:       int reverse_str(char *str)
Description:    将句子中单词位置倒置，不改变单词的结构
Calls:          int reverse(char *head, char *tail)
Called By:      main
Input:          char *str
Return:         no
*************************************************/ 
int reverse_str(char *str)
{
    char *head = str;
    char *tail;

    /*遍历字符串将每个单词的头和尾找出来，并将其逆序 */
    while(*str != '\0')
    {
        if(*str == ' ' || *str == '\0')
        {
            tail = str - 1;
            reverse(head, tail);             //调用reverse 函数，将找到的每个单词逆序
            head = str + 1;                  //空格下一个即为下一个单词开头
        }

        str++;
    }
}

int main()
{
    char str[100];                            //源字符串
        
    printf("input a string : ");
    gets(str);

    reverse(str, str + strlen(str) - 1);      //掉用reverse 函数将所有字符全部逆序 '\0'除外
    reverse_str(str);                         //调用reverse 将每个单词逆序

    printf("output str :%s\n",str);

    return 0;
}
