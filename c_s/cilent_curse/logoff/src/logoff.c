/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

extern int power;

int logoff()
{
	msg.action = LOGOFF;
 
    if(write(sockfd,&msg,sizeof(msg))==-1) 
	{
        fprintf(stderr,"logoff write Error:%s\n",strerror(errno)); 
    }
    
    refresh();
    endwin();
    
    msg.state = NOTLINE;
    
    system("clear");

    win_ok = 0;
    power = 0;

  
//    printf("\t\t\033[47;31m*按任意键返回。。。。  *\033[0m\n");
//    getchar();

    return 0;
}
