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
    initscr(); /*初始化屏幕*/
	if(start_color() == OK) /*开启颜色*/
	{
		init_pair(1, COLOR_BLUE, COLOR_WHITE); /*建立一个颜色对*/
		attron(COLOR_PAIR(1)); /*开启字符输出颜色*/
		move(LINES/2, COLS/2);
		waddstr(stdscr, " Hello, world!");
		attroff(COLOR_PAIR(1)); /*关闭颜色显示*/
		refresh();
		getch();
	}
	else
	{
		waddstr(stdscr, "Can not init color");
		refresh();
		getch();
	}
	    endwin(); /*关闭curses状态*/
return 0;
}
