/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <termio.h>
#include <netdb.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <fcntl.h>
#include <sqlite3.h>
#include <time.h>
#include <curses.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

char passwd[20];

char my_getch(void)
{
     struct termios tm, tm_old;
     int fd = 0, ch;
 
     if (tcgetattr(fd, &tm) < 0) 
     {                            //保存现在的终端设置
          return -1;
     }
 
     tm_old = tm;
     cfmakeraw(&tm);             //更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
     if (tcsetattr(fd, TCSANOW, &tm) < 0)
     {                           //设置上更改之后的设置
          return -1;
     }
 
     ch = getchar();
     if (tcsetattr(fd, TCSANOW, &tm_old) < 0) 
     {                              //更改设置为最初的样子
          return -1;
     }
    
     return ch;
}

char *GetPasswd()
{
    unsigned char c;
    int i = 0;
    
    while ((c=getch())!='\r')
    {
        if (i<20 && isprint(c))
        {
            passwd[i++] = c;
            putchar('*');
        }
        else if (i>0 && c=='\b')
        {
            --i;
            putchar('\b');
        }
    }
    putchar('\n');
    passwd[i] = '\0';
    
    return passwd;
}

int main()
{
    GetPasswd();
    printf("%s",passwd);
}

