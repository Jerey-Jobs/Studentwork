/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int rname()
{
	msg.action = RNAME;
    
    mvwprintw(scan_win, 2, 1, "                                                   ");
    mvwprintw(scan_win, 2, 1, "new name: ");
    wrefresh(scan_win);
    echo();
    mvwscanw(scan_win,2,15,"%s",msg.name);

	if(write(sockfd,&msg,sizeof(msg)) == -1) 
	{
        fprintf(stderr,"rname write Error:%s\n",strerror(errno)); 
    }
 
    return 0;
}
