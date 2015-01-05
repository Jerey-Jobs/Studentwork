/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"


int cilent_regist()
{
	msg.action = REGIST;

    int i;
	char tmp_password1[20];
	char tmp_password2[20];
	
	printf("输入昵称 ：");
	scanf("%s",msg.name);
	printf("输入密码 ：");
    getchar();	
    for(i = 0; i < 20; i++)
    {
        tmp_password1[i] = my_getch();
        if(tmp_password1[i] == '\r')
        {
        	tmp_password1[i] = '\0';
        	break;
        }
        printf("*");
    }
    printf("\n");
    

	printf("确认密码 ：");
	for(i = 0; i < 20; i++)
    {
        tmp_password2[i] = my_getch();
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
    	printf("两次密码不同，请重新注册！\n");
    	cilent_regist();
    }
    else
    {   
    	strcpy(msg.password,tmp_password1);
        
        regist_back = 0;

    	if(write(sockfd,&msg,sizeof(msg))==-1) 
	    {
            fprintf(stderr,"regist write Error:%s\n",strerror(errno)); 
        }
   
        while(regist_back != REGIST_OK)
        {
            printf("正在注册、、、、稍等！\n");         
            sleep(3);
        }

        printf("注册成功！并已帮您登陆！\n");

        msg.state = LINE;          

    }

    printf("\t\t\033[47;31m 按任意键返回！\033[0m\n");
    getchar();

    return 0;
}
