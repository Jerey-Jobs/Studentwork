/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <curses.h>

int main()
{
    WINDOW *new_window_ptr;
    WINDOW *new_window_ptr2;
    WINDOW *scan_win;
    WINDOW *help_win;

    WINDOW *popup_window_ptr;
    int x_loop;
    int y_loop;
    char a_letter = 'a';

    initscr();
    echo();

    char str[20];

    new_window_ptr = newwin(20, 18, 0, 0);
    new_window_ptr2 = newwin(20, 40, 0, 20);
    scan_win = newwin(5,40,20,20);
    help_win = newwin(20,18,0,62);

    box(scan_win, ACS_VLINE, ACS_HLINE);
    box(new_window_ptr, ACS_VLINE, ACS_HLINE);
    box(new_window_ptr2, ACS_VLINE, ACS_HLINE);
    box(help_win, ACS_VLINE, ACS_HLINE);

    refresh();
    mvwscanw(scan_win,1,2,"%s",str);
    mvwprintw(new_window_ptr, 1, 1, "%s", str);
    wrefresh(new_window_ptr);
   
    mvwprintw(scan_win, 1, 1, "                 ");
    refresh();


    echo();
    mvwscanw(scan_win,2,2,"%s",str);
    mvwprintw(new_window_ptr2, 1, 1, "%s", str);
    mvwprintw(help_win, 1, 1, "help");
    refresh();
    wrefresh(new_window_ptr);
    wrefresh(new_window_ptr2);
    wrefresh(help_win);

    sleep(10);
    endwin();
    exit(1);

  return 0;
}