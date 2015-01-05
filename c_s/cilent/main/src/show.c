/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int show()
{
	msg.action = SHOW;


    if(write(sockfd,&msg,sizeof(msg))==-1) 
	{
        fprintf(stderr,"show regist write Error:%s\n",strerror(errno)); 
    }
     

    return 0;
}
