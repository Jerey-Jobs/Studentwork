/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/
#include "../../include/myhead.h"

int win_init_admin()
{

    initscr();
    echo();

    line_chat = 1;
    win_ok = 1;

    log_win = newwin(3, 65, 0, 27);
    show_win = newwin(21, 25, 4, 0);
    chat_win = newwin(21, 65, 4, 27);
    scan_win = newwin(5,65,24,27);
    help_win = newwin(21,25,4,94);

    box(log_win, ACS_VLINE, ACS_HLINE);
    box(scan_win, ACS_VLINE, ACS_HLINE);
    box(show_win, ACS_VLINE, ACS_HLINE);
    box(chat_win, ACS_VLINE, ACS_HLINE);
    box(help_win, ACS_VLINE, ACS_HLINE);

    mvwprintw(log_win, 1, 18, " ********JJ chat room*********");
    mvwprintw(show_win, 1, 1, "local people:");
    mvwprintw(show_win, 3, 1, "line people:");
    mvwprintw(scan_win, 1, 1, " ");
    mvwprintw(chat_win, 1, 1, " ");
    mvwprintw(help_win, 1, 1, "help window    | cmd");
    mvwprintw(help_win, 2, 1, "_______________|_______");   
    mvwprintw(help_win, 3, 1, "line person    |show ");
    mvwprintw(help_win, 4, 1, "chat people    |chat");
    mvwprintw(help_win, 5, 1, "broadcast      |broad");
    mvwprintw(help_win, 6, 1, "face look      |hi");
    mvwprintw(help_win, 7, 1, "change password|cpwd ");
    mvwprintw(help_win, 8, 1, "change name    |rname");
    mvwprintw(help_win, 9, 1, "logoff         |logoff");
    mvwprintw(help_win, 10, 1,"quit           |exit ");
    mvwprintw(help_win, 11, 1,"kick person    |kick ");
    mvwprintw(help_win, 12, 1,"ban someone    |ban ");
    mvwprintw(help_win, 13, 1,"rid ban        |rid ");
    wrefresh(log_win);
    wrefresh(show_win);
    wrefresh(chat_win);
    wrefresh(help_win);
    wrefresh(scan_win);


    return 0;
}
