/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 100

int resever_string(char *src)
{
    int i;
    int len = strlen(src);
    char tmp;

    for(i = 0; i < len / 2; i++)
    {
        tmp = *(src + i);
        *(src + i) = *(src + len - 1 - i);
        *(src + len - 1 - i) = tmp;
    }

}

int main()
{
    char src[MAX];

    printf("please input string : ");
    scanf("%s",src);

    resever_string(src);

    printf("the resever string is: %s\n",src);

    return 0;
}
