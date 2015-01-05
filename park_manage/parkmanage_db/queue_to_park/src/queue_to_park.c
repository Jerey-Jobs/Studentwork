/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：    queue_to_park.c
Author：Jerey_Jobs    Version:0.1    Date:2014.11.23 
Description：对列进停车栈函数
Funcion List: NO
*****************************************************/

#include "../../include/myhead.h"

int queue_to_park()
{
    if((tail - front) > 0)          //若等候队列非空
    {
        front++;                    //队首指针后移
         
        top_park++;                 //停车栈顶加一

        park[top_park] = queue[front];      //等候队列首等于停车栈
    }
}
