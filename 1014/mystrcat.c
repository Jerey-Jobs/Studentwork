/*************************************************
Copyright (C), 1988-1999, Lighting Tech.Co., Ltd.
File name:  my_strcat
Author:  Jerey     Version: 0.1       Date: 2014/10/14
Description:实现字符串的连接及字符串的复制    
Function List: 
             1.my_strcat(char *str, char *ptr)
             2.*my_strcpy(char *str, char *ptr)
Date: 10/14                     
*************************************************/

#include<stdio.h>
/*************************************************
Function:       my_strcat(char *str, char *ptr)
Description:    实现2个字符串的连接
Calls:          no
Called By:      main
Input:          str   头字符串
                ptr   尾字符串
Return:         no     
*************************************************/

/*实现2个字符串的连接*/
void my_strcat(char *str, char *ptr)
{

    while(*str != '\0')         //将*str指向str结尾
    {
        str++;
    }

    while(*ptr != '\0')         //ptr头赋值到str尾
    {
        *str = *ptr; 
        str++;
        ptr++;
    }
    *str = '\0';

}

/*************************************************
Function:       *my_strcat(char *str, char *ptr)
Description:    实现字符串的复制
Calls:          no
Called By:      main
Input:          str  复制进字符串
                ptr  被复制目标

Return:         str
**************************************************/

/*实现字符串的复制 */
char *my_strcpy(char *str, char *ptr)
{
    char *tmp =  str;              //暂存指针地址

    while(*ptr != '\0')            //拷贝字符串
    {
        *str = *ptr;
        str++;
        ptr++;
    }
    *str = '\0';

    str = tmp;                     //指针返回初值

    return str;
}


int main()
{
    char str[100];                //目标字符串1
    char ptr[100];                //目标字符串2

    printf("now ! input str:");
    gets(str);
    printf("now ! input ptr:");
    gets(ptr);

    my_strcat(str, ptr);          //调用my_strcat 连接头尾字符串str and ptr

    printf("strcat output: %s\n",str);
    printf("strcpy output: %s\n",my_strcpy(str,ptr));  //调用my_strcpy 复制ptr进str
    return 0;
}
