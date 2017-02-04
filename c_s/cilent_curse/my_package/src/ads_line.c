/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

void *ads_show(void *arg)
{
    int i;

    for(i = 0; i < 123; i++)
    {
         wclear(line_win);                       //清空chat窗口
         mvwprintw(line_win, 0 , i , ads_buf);
         wrefresh(line_win);

         usleep(200000);

         if(i == 122)
         {
             i = 0;         	
         }
    }
}
