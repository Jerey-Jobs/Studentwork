/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：admin_ads.c
Author：Jerey_Jobs    Version:0.1    Date:2015/1/20 
Description：管理员发广告的操作
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int admin_ads()
{
    msg.action = ADS;

    mvwprintw(scan_win, 1, 1, "                                     ");
    wrefresh(scan_win);
    mvwprintw(scan_win, 1, 1, "advertise : ");           //聊天对象
    wrefresh(scan_win);
    echo();
    mvwgetnstr(scan_win,1,15,msg.msg,MAX_LEN);

    my_gettime();                                       //调用gettime获取当前时间,更新c_time中内容

    char write_buf[MAX];

    sprintf(write_buf, "%s admin set an advertise",c_time);

    wprintw(chat_win,"<<<%s\n",write_buf);   //打印提示信息
    wrefresh(chat_win);

    if(write(sockfd,&msg,sizeof(msg))==-1)              //将数据写给服务器
	{
        mvwprintw(tips_win, 1, 2, "write Error");
        wrefresh(tips_win);       
    }
   
    write_line(write_buf);

    return 0;
}
