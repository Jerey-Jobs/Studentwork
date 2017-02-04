/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

int str2int(const char *src)
{
    int sum = 0;
   
    while(*src != '\0')
    {
        sum = sum * 10 + (*src - '0');
        src++;
    }

    return sum;
}

int main()
{
    char str[MAX];
    int result;

    printf("please input the string : ");
    scanf("%s",str);

    result = str2int(str);

    printf("the result is: %d\n",result);

    return 0;
}
