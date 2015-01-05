/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int ban()
{
	msg.action = BAN;
	
    printf("\t\t\033[47;31m*请输入要禁言的昵称：*\033[0m");
     
    scanf("%s",msg.toname);


 	if(write(sockfd,&msg,sizeof(msg))==-1) 
	{
        fprintf(stderr,"ban write Error:%s\n",strerror(errno)); 
    }

    printf("\t\t\033[47;31m 按任意键返回！\033[0m\n");
    getchar();
        getchar();


    return 0;
}
