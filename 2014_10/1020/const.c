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

    int num;

    const int *const p = &num;

    num++;
    p++;
    (*p)++;

    return 0;
}
