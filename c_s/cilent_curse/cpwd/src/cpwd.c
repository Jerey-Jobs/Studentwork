/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：cpwd.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.18 
Description：改密码函数
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int cpwd()
{
	msg.action = CPWD;

	char tmp_password1[20];               //存放第一次输入
	char tmp_password2[20];               //存放第二次输入
	
	mvwprintw(scan_win, 2, 1, "                                                   ");
    mvwprintw(scan_win, 2, 1, "new password:     ");
    wrefresh(scan_win);
    echo();
    mvwscanw(scan_win,2,20,"%s",tmp_password1);

    mvwprintw(scan_win, 3, 1, "                                                   ");
    mvwprintw(scan_win, 3, 1, "confirm password: ");
    wrefresh(scan_win);
    echo();
    mvwscanw(scan_win,3,20,"%s",tmp_password2);

    /*比较2次输入的异同，若相同则发送数据至服务器，若不同则提示并重新改密*/
    if(strcmp(tmp_password1,tmp_password2) != 0)
    {
        mvwprintw(tips_win, 1, 2, "                                                   ");
        mvwprintw(tips_win, 1, 2 , "two different password");
        wrefresh(tips_win);
        cpwd();
    }
    else
    {   
    	strcpy(msg.password,tmp_password1);

    	if(write(sockfd,&msg,sizeof(msg))==-1) 
	    {
            fprintf(stderr,"regist write Error:%s\n",strerror(errno)); 
        }
    
        
    }

    return 0;
}
