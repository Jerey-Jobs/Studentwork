/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：way_to_park.c
Author：Jerey_Jobs    Version:0.1    Date:2014.11.23
Description：取让路栈一辆车进停车场栈
Funcion List: NO
*****************************************************/

#include "../../include/myhead.h"

int way_to_park()
{
    /*若让路栈非空*/
    if(top_way == -1)
    {
        printf("让路栈已空\n");       

        return WAY_EMPTY;
    }
    /*取让路栈一辆车进停车场栈*/
    else
    {
        top_park++;               

        park[top_park] = way[top_way];   //将让路栈顶赋值为停车栈顶

        top_way--;                       //让路栈顶减一

        return 0;
    }

    return 0;
}
