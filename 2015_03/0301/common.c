/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int main()
{
    int a,b;
    int c;
    int multi;
    int max;

    scanf("%d%d",&a,&b);

    multi = a * b;
    c = a % b;
  
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }

    max = multi / b;

    printf("%d %d",b,max);

    return 0;
}
