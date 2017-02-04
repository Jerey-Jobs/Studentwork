/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <stdlib.h>


int fn1()
{

    printf("eeeee");
    return 0;
}

int main()
{
    _onexit( fn1 );
    printf("exit\n");

    return 0;
}
