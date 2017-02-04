/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/
#include "../../include/myhead.h"

extern void *clear_tips(void *arg);

int win_init_admin()
{
    initscr();                            //开启curses模式
    echo();                               //开启回显模式
    cbreak();
    noecho();
    nonl();

    win_ok = 1;

    start_color();                               //开启颜色
    init_pair(1, COLOR_BLACK, COLOR_WHITE);      //建立一个颜色对
 
    log_win = newwin(3, 65, 0, 27);
    show_win = newwin(21, 25, 4, 0);
    chat_box_win = newwin(21, 67, 4, 26);
    chat_win = newwin(18, 65, 5, 27);
    scan_win = newwin(5,65,24,27);
    help_win = newwin(21,25,4,94);
    tips_win = newwin(3,67,23,26);

    line_win = newwin(1,123,3,0);

    scrollok(chat_win, TRUE);


    box(log_win, ACS_VLINE, ACS_HLINE);               //给5个窗口画框
    box(scan_win, ACS_VLINE, ACS_HLINE);
    box(show_win, ACS_VLINE, ACS_HLINE);
    box(chat_box_win, ACS_VLINE, ACS_HLINE);
    box(help_win, ACS_VLINE, ACS_HLINE);
    box(tips_win, ACS_VLINE, ACS_HLINE);
    
    wattrset(log_win,COLOR_PAIR(1));                  //开启字符输出颜色
    wattrset(scan_win,COLOR_PAIR(1));                 //开启字符输出颜色
   
   
    /*打印出初始化的界面的内容*/
    mvwprintw(log_win, 1, 18, " xiamin's chatroom QQ 610315802");
    mvwprintw(show_win, 1, 1, "local people:");
    mvwprintw(show_win, 3, 1, "line people:");
    mvwprintw(scan_win, 1, 1, " ");
    mvwprintw(chat_win, 1, 1, " ");
    mvwprintw(help_win, 1, 1, "help window    | cmd");
    mvwprintw(help_win, 2, 1, "_______________|_______");   
    mvwprintw(help_win, 3, 1, "chat           |chat");
    mvwprintw(help_win, 4, 1, "broadcast      |broad");
    mvwprintw(help_win, 5, 1, "change password|cpwd ");
    mvwprintw(help_win, 6, 1, "change name    |rname");
    mvwprintw(help_win, 7, 1, "exit           |exit ");
    mvwprintw(help_win, 8, 1, "chat record    |record");
    mvwprintw(help_win, 9, 1, "end record     |end");
    mvwprintw(help_win, 10, 1,"send file      |send");
    mvwprintw(help_win, 11, 1,"_______________|_______");   
    mvwprintw(help_win, 12, 1,"kick person    |kick ");
    mvwprintw(help_win, 13, 1,"ban someone    |ban ");
    mvwprintw(help_win, 14, 1,"rid ban        |rid ");
    mvwprintw(help_win, 15, 1,"advertise      |ads ");

    wrefresh(log_win);
    wrefresh(show_win);
    wrefresh(chat_win);
    wrefresh(help_win);
    wrefresh(scan_win);
    wrefresh(chat_box_win);
    wrefresh(tips_win);
 
    pthread_t clear_id;
    pthread_create(&clear_id,NULL,(void *)clear_tips,NULL);

    return 0;
}
