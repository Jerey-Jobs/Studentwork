/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：park_to_park.c
Author：Jerey_Jobs    Version:0.1    Date: 2014.11.23
Description：  将停车场栈顶取出一辆放进让路栈
Funcion List:  NO
*****************************************************/

#include "../../include/myhead.h"

int park_to_way()
{
    /*判断停车场是否为空*/
    if(top_park == -1)
    {
        printf("停车场己空!\n");
        return PARK_EMPTY;
    }
    else
    {
        top_way++;                       //让路栈栈顶指针加一

        way[top_way] = park[top_park];   //让路栈栈顶等于停车场栈顶

        top_park--;                      //停车场栈顶减一

        return TO_WAY_OK;
    }
}
