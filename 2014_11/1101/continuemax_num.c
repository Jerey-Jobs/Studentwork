/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

int continuemax_num(const char *input,char *output)
{
    int max = 0;
    int len = 0;
    char *flag = output;

    while(*input != '\0')
    {
        while((*input > '0') && (*input < '9'))
        {
            len++;
            *output = *input;
            input++;
            output++;
        }

        if(max < len)
        {
            max = len;
            len = 0;
            *output = '\0';
            output = flag;
        }

        input++;
    }

    return max;
}


int main()
{
    char src[MAX];
    char ptr[MAX];
    int max;

    printf("please input the  string : ");
    scanf("%s",src);

    max = continuemax_num(src,ptr);

    printf("the continue max  num is : %d\n",max);

    printf("the continue max string  is : %s\n",ptr);


    return 0;
}
