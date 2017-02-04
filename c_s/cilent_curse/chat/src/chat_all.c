/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：chat_all.c
Author：Jerey_Jobs    Version:0.1    Date:2015/1/18 
Description：执行广播操作函数
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int broad()
{
    /*判断是否是禁言状态，若是则提示并返回*/
    if(msg.state == CHAT_BAN)
    {
        mvwprintw(tips_win, 1, 1, "you have been banned ,you can't broad");
        wrefresh(tips_win);
      
        return CHAT_BAN;
    }

	msg.action = BROAD;

    mvwprintw(scan_win, 2, 1, "message : ");            //输入广播内容s
    wrefresh(scan_win);
    echo();
    mvwgetnstr(scan_win,2,15,msg.msg,MAX_LEN);

    check_msg(msg.msg);      //检查是否有不文明用语
                                      
    char write_buf[MAX];

    my_gettime();     //调用gettime获取当前时间,更新c_time中内容
   
    sprintf(write_buf,"%s you talk to all people : %s",c_time,msg.msg);
    
    wprintw(chat_win,"<<<%s\n",write_buf);
    wrefresh(chat_win);

    
    if(write(sockfd,&msg,sizeof(msg))==-1)              //将数据写给服务器
	{
        fprintf(stderr,"regist write Error:%s\n",strerror(errno)); 
    }

    /*将该聊天消息写入聊天记录文件*/

    write_line(write_buf);

    return 0;
}
