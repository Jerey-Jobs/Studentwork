/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/
#include "../../include/myhead.h"

int send_file()
{
	if(msg.state == CHAT_BAN)
    {
        mvwprintw(tips_win, 1, 2, "you have been banned ,you can't send");
        wrefresh(tips_win);
      
        return CHAT_BAN;
    }
    else
    {       
        mvwprintw(tips_win, 19, 2, "only support send small file !!!");
        wrefresh(tips_win);
    }

	msg.action = SEND_FILE;

    mvwprintw(scan_win, 1, 1, "                                     ");
    wrefresh(scan_win);
    mvwprintw(scan_win, 1, 1, "send name : ");
    wrefresh(scan_win);
    echo();
    mvwscanw(scan_win,1,15,"%s",msg.toname);

    mvwprintw(scan_win, 2, 1, "file path: ");
    wrefresh(scan_win);
    echo();
    mvwgetstr(scan_win,2,15,msg.file_name);

    my_gettime();
    wprintw(chat_win,"%s you send %s to %s\n",c_time,msg.file_name,msg.toname);
    wrefresh(chat_win);
/*
    mvwprintw(chat_win, 19, 2, "                                                   ");
    mvwprintw(chat_win, 19 , 2 , "wait %s confirm",msg.toname);
    wrefresh(chat_win);
*/
    if((fp = fopen(msg.file_name,"a+")) == NULL)
    {
        mvwprintw(tips_win, 1, 2, "                                                   ");
        mvwprintw(tips_win, 1 , 2 , "open file error");
        wrefresh(tips_win);
    }

    char read_line_buf[MAX];
    
    while(read_line(fp,read_line_buf) != 0)
    {
        strcpy(msg.msg,read_line_buf);
      
        if(write(sockfd,&msg,sizeof(msg)) == -1) 
	    {
            fprintf(stderr,"regist write Error:%s\n",strerror(errno)); 
        }
    }

    fclose(fp);

    char write_buf[MAX];
    memset(write_buf,0,sizeof(write_buf));

    sprintf(write_buf, "%s you send %s to %s",c_time,msg.file_name,msg.toname);

    write_line(write_buf);

    return 0;
}
