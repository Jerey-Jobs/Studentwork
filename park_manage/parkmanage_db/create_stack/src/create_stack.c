/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：create_stak.c
Author：Jerey_Jobs    Version:0.1    Date: 2014.11.23
Description：  初始化函数，初始化栈，队列
Funcion List:  void create_stack()
*****************************************************/

#include "../../include/myhead.h"

void create_stack()
{
    top_park = -1;             //初始化停车场栈，即栈顶指针置-1
    top_way = -1;              //初始化让路栈，即栈顶指针置-1
    front = -1;                //初始化队列，头和尾都为-1
    tail = -1;
}
