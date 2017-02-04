/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/


#include <curses.h>
#include <signal.h>

static int finish(int sig);

WINDOW *scrwin, *boxwin;

int main()
{
	int i;
	char ch;

	initscr();
	cbreak();
	noecho();
	nonl();

	scrwin=newwin(10, 40 , LINES/2-6 , COLS/2-25) ;
	boxwin=newwin(12, 42 , LINES/2-7 , COLS/2-26) ;

	scrollok(scrwin, TRUE) ;
	box(boxwin, '*', '*');

	refresh();
	wrefresh(boxwin);

	signal(SIGINT,finish);
	signal(SIGQUIT,finish);

	for(i=0;; i++)
	{
		if(i%20==0)
		sleep(1); // 把这行删掉,看看会有什么后果！ J
		wprintw(scrwin, "output string %d\n" , i%9) ;
		wrefresh(scrwin);
	}
	return 0;
}
 
int finish(int sig)
{
endwin();
exit(0);
}
