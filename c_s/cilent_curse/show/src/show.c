/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：show.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.18 
Description：向服务器发送显示当前在线用户的命令
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int show()
{
	msg.action = SHOW;      //动作为显示当前在线用户

    clear_show();           //清屏

    //发送消息
    if(write(sockfd,&msg,sizeof(msg))==-1) 
	{
        fprintf(stderr,"show regist write Error:%s\n",strerror(errno)); 
    }
     
    return 0;
}
