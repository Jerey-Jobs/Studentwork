/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

void *clear_tips(void *arg)
{
    while(1)
    {
    	if(clear_flag == CLEAR_START)
    	{
    		sleep(4);
            mvwprintw(tips_win, 1, 1, "                                                       ");
            wrefresh(tips_win);
            clear_flag = 0;
        }
    }

    return NULL;
}
