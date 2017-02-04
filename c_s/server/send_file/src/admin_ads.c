/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：admin_ads.c
Author：Jerey_Jobs    Version:0.1    Date: 2015.1.22
Description：管理员打广告操作
Funcion List: int admin_ads(int fd,MSG buf)
*****************************************************/

#include "../../include/myhead.h"

int admin_ads(int fd,MSG buf)
{
	printf("打广告开始！\n");

    MSG str = buf;

    LINK tmp = head;

    str.action = ADS;

    /*遍历用户链表向当前在线的人发送广告信息*/
    while(tmp != NULL)
    {
        if(tmp->state == LINE)
        {
        	write(tmp->fd,&str,sizeof(str));
            printf("打广告 内容 %s\n",str.msg); 
        }
 
    	tmp = tmp->next;
    }
    
    /*同时告诉管理员打广告成功*/
    str.action = ADS_OK;
    
    write(fd,&str,sizeof(str));

    return 0;
}
