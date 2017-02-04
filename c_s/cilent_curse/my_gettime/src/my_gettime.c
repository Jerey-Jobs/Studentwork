/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：my_gettime.c
Author：Jerey_Jobs    Version:0.1    Date: 2015.1.18
Description：获取当前时间函数
Funcion List: NO
*****************************************************/

#include "../../include/myhead.h"

int my_gettime()
{
	time_t timep;         

	struct tm *p;              //存放时间结构体
	
	time(&timep);

	p = localtime(&timep);     //获取当前时间

	sprintf(c_time,"%d:%d:%d ",p->tm_hour,p->tm_min,p->tm_sec);   //将获取到的时间格式化存进c_time中

    return 0;
}
