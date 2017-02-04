/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：rid_people.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.18 
Description： 解除禁言操作
Funcion List: 
*****************************************************/
#include "../../include/myhead.h"

int rid_people()
{	
	msg.action = RID_PEOPLE;   //动作为解除禁言操作

    /*输入需要解除禁言的对象*/
    mvwprintw(scan_win, 1, 1, "                                     ");
    wrefresh(scan_win);
    mvwprintw(scan_win, 1, 1, "kick person : ");
    wrefresh(scan_win);
    echo();
    mvwscanw(scan_win,1,15,"%s",msg.toname);

    /*发送消息*/
 	if(write(sockfd,&msg,sizeof(msg))==-1) 
	{
        fprintf(stderr,"ban write Error:%s\n",strerror(errno)); 
    }

    return 0;
}
