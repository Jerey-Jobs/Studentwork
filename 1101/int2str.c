/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

char * int2str(const int num)
{
    int i;
    int len = 0;
    int tmp = num;
    static char str[MAX];
    char temp;
    char *p = str;


    while(tmp > 0)
    {
        *p = tmp % 10 + '0';
        tmp = tmp / 10;
        len++;
        p++;
    }
    *p = '\0';

    for(i = 0; i < len / 2; i++)
    {
        temp = *(str + i);
        *(str + i) = *(str + len - 1 - i);
        *(str + len - 1 - i) = temp;
    }
    return str;

}
int main()
{
    int num;

    printf("please input the number : ");
    scanf("%d",&num);

    printf("the string is : %s\n",int2str(num));

    return 0;
}
