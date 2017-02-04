/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：chat_record.c
Author：Jerey_Jobs    Version:0.1    Date:2015/1/18 
Description： 写入或读取聊天记录的相关函数
Funcion List:   
                int write_line(char *s) 
                int read_line(FILE *fp,char *buf)
                int chat_record()
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:     int write_line(char *s)   
Description:  向文件中写入一行内容 
Calls:        NO         
Called By:      
Input:        char *s 所要写入的字符串  
Return:       NO
*************************************************/ 
int write_line(char *s) 
{
    char msg_name_buf[MAX];

    sprintf(msg_name_buf,"record_file/%s",msg.name);

    if((fp = fopen(msg_name_buf,"a+")) == NULL)             
    {
        mvwprintw(tips_win, 1, 2, "                                                   ");
        mvwprintw(tips_win, 1, 2 , "open file error");
        wrefresh(tips_win);
    }

    fputs(s,fp);                                        //将内容写入

    fputc('\n',fp);                                     //并加上换行号
    
    fclose(fp);              

    return 0;
}

/*************************************************
Function:     int read_line(FILE *fp,char *buf)  
Description:    读取文件一行函数
Calls:         NO
Called By:     
Input:         FILE *fp      所读文件指针
               char *buf     存放读出内容
Return:         
*************************************************/ 
int read_line(FILE *fp,char *buf)
{
    int i;
    char tmp;             //存放读出字符

    /*挨个读出字符直到读出换行符号为止*/
    for(i = 0; i < MAX; i++)
    {
        tmp = getc(fp);

        if(tmp == '\n')
        {
            buf[i] = '\n';
            buf[i + 1] = '\0';
            i++;
            return i;
        }

        buf[i] = tmp;
    }
    return 0;
}

/*************************************************
Function:       int chat_record()
Description:    读取聊天记录函数
Calls:          
Called By:      
Input:          NO
Return:         NO
*************************************************/ 
int chat_record()
{
    char file_path[MAX];

    sprintf(file_path,"/mnt/hgfs/share/Jerey/c_s/cilent_curses/%s",msg.name);

    char msg_name_buf[MAX];

    sprintf(msg_name_buf,"record_file/%s",msg.name);

    /*打开文件并做 出错处理*/
    if((fp = fopen(msg_name_buf,"a+")) == NULL)
    {
        mvwprintw(tips_win, 1, 2, "                                                   ");
        mvwprintw(tips_win, 1, 2 , "open file error");
        wrefresh(tips_win);
    }

    clear_chat();                              //先将chat窗口清屏

    char read_line_buf[10240];

    /*一行一行读出文件内容并打印出来 直到读到文件末尾*/
    while(read_line(fp,read_line_buf) != 0)
    {

        wprintw(chat_win,"%s", read_line_buf);
        wrefresh(chat_win);
    }

    fclose(fp);

    return 0;
}
