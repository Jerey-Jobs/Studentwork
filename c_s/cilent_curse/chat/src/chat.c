/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：chat.c
Author：Jerey_Jobs    Version:0.1    Date: 2015/1/19
Description：聊天函数
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int chat()
{
    /*判断是否是禁言状态，若是则提示并返回*/
    if(msg.state == CHAT_BAN)
    {
        mvwprintw(tips_win, 1, 1, "you have been banned ,you can't chat              ");
        wrefresh(tips_win);
      
        return CHAT_BAN;
    }

	msg.action = CHAT;

    /*提示输入并读取输入内容*/
    mvwprintw(scan_win, 1, 1, "                                     ");
    wrefresh(scan_win);
    mvwprintw(scan_win, 1, 1, "chat name : ");           //聊天对象
    wrefresh(scan_win);
    echo();
    mvwgetnstr(scan_win,1,15,msg.toname,SHORT_LEN);

    mvwprintw(scan_win, 2, 1, "message : ");             //输入聊天内容
    wrefresh(scan_win);
    echo();
    mvwgetnstr(scan_win,2,15,msg.msg,MAX_LEN);

    check_msg(msg.msg);

    my_gettime();                                        //调用gettime获取当前时间,更新c_time中内容

    char write_buf[MAX];

    sprintf(write_buf, "<<<%s you talk to %s : %s",c_time,msg.toname,msg.msg);

    wprintw(chat_win,"%s\n",write_buf);   //打印提示信息
    wrefresh(chat_win);

    if(write(sockfd,&msg,sizeof(msg)) == -1)             //将数据写给服务器
	{
        fprintf(stderr,"regist write Error:%s\n",strerror(errno)); 
    }
   
    /*将该聊天消息写入聊天记录文件*/
    write_line(write_buf);

    return 0;
}
