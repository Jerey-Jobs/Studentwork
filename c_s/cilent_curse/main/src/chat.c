/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int chat()
{
    if(msg.state == CHAT_BAN)
    {
        mvwprintw(chat_win, 19, 1, "you have been banned ,you can't chat");
        wrefresh(chat_win);
      
        return CHAT_BAN;
    }

	msg.action = CHAT;

    mvwprintw(scan_win, 1, 1, "                                     ");
    wrefresh(scan_win);
    mvwprintw(scan_win, 1, 1, "chat name : ");
    wrefresh(scan_win);
    echo();
    mvwscanw(scan_win,1,15,"%s",msg.toname);

    mvwprintw(scan_win, 2, 1, "message : ");
    wrefresh(scan_win);
    echo();
    mvwscanw(scan_win,2,15,"%s",msg.msg);
    
    mvwprintw(chat_win, line_chat++, 2, "you talk to %s : %s",msg.toname,msg.msg);
    wrefresh(chat_win);

    if(write(sockfd,&msg,sizeof(msg)) == -1) 
	{
        fprintf(stderr,"regist write Error:%s\n",strerror(errno)); 
    }

    return 0;
}
