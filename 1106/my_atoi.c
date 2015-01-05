/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int my_atoi(char *p)
{
    int result = 0;
    int tmp = 1;
    
    while(*p != '\0')
    {
        if(*p == '-')
        {
            tmp = -1;
        }
        else
        {
            result = result * 10 + *p - '0';
        }
        p++;

    }

    return result * tmp;
}

int main()
{
    char *src1 = "-100";
    char *src2 = "200";

    int sum;
    sum = my_atoi(src1) + my_atoi(src2);
    printf("sum is : %d\n",sum);

    return 0;
}
