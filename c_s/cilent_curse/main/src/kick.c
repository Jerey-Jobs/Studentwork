/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int kick()
{
	msg.action = KICK;

    mvwprintw(scan_win, 1, 1, "                                     ");
    wrefresh(scan_win);
    mvwprintw(scan_win, 1, 1, "kick person : ");
    wrefresh(scan_win);
    echo();
    mvwscanw(scan_win,1,15,"%s",msg.toname);

    if(write(sockfd,&msg,sizeof(msg))==-1) 
	{
        fprintf(stderr,"kick write Error:%s\n",strerror(errno)); 
    }

    return 0;
}
