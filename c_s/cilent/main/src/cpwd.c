/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int cpwd()
{
	msg.action = CPWD;

    int i;
	char tmp_password1[20];
	char tmp_password2[20];
	
	
	printf("\t\t\033[47;31m 请输入新密码：\033[0m");
    for(i = 0; i < 20; i++)
    {
        tmp_password1[i] = getch();
        if(tmp_password1[i] == '\r')
        {
        	tmp_password1[i] = '\0';
        	break;
        }
        printf("*");
    }
    printf("\n");
    

    printf("\t\t\033[47;31m  确认密码：\033[0m");
	for(i = 0; i < 20; i++) 
    {
        tmp_password2[i] = getch();
        if(tmp_password2[i] == '\r')
        {
        	tmp_password2[i] = '\0';
        	break;
        }
        printf("*");
    }
    printf("\n");

    if(strcmp(tmp_password1,tmp_password2) != 0)
    {
    	printf("\t\t\033[47;31m 两次输入不同，请重新改密：\033[0m");
    	rname();
    }
    else
    {   
    	strcpy(msg.password,tmp_password1);

    	if(write(sockfd,&msg,sizeof(msg))==-1) 
	    {
            fprintf(stderr,"regist write Error:%s\n",strerror(errno)); 
        }
    
        
    }

    printf("\t\t\033[47;31m 按任意键返回！\033[0m\n");
    getchar();
    getchar();


    return 0;
}
