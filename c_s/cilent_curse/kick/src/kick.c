/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：kick.c
Author：Jerey_Jobs    Version:0.1    Date: 2015.1.18
Description： 踢人函数
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int kick()
{
	msg.action = KICK;                  //行为为踢人

    mvwprintw(scan_win, 1, 1, "                                     ");           //执行输入
    wrefresh(scan_win);
    mvwprintw(scan_win, 1, 1, "kick person : ");
    wrefresh(scan_win);
    echo();
    mvwscanw(scan_win,1,15,"%s",msg.toname);

    /*将信息发送至服务器*/
    if(write(sockfd,&msg,sizeof(msg))==-1) 
	{
        fprintf(stderr,"kick write Error:%s\n",strerror(errno)); 
    }

    return 0;
}
