/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name： regist.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.18 
Description： 用户注册函数
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int cilent_regist()
{
	msg.action = REGIST;

    int i;
	char tmp_password1[20];        //存放第一次输入
	char tmp_password2[20];        //存放第二次输入
	
	printf("\t\t\t\t输入昵称(<20字符)：");
	scanf("%s",msg.name);
	printf("\t\t\t\t输入密码(<20字符)：");
    getchar();	

    /*用不回显方式输入密码 输入一个字符打印一个 * 号*/
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
    
	printf("\t\t\t\t确认密码(<20字符)：");
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

    /*比较2次输入的异同，若相同则发送数据至服务器，若不同则提示并重新注册*/
    if(strcmp(tmp_password1,tmp_password2) != 0)
    {
    	printf("\t\t\t\t两次密码不同，请重新注册！\n");
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
   
        /*等待服务器返回注册成功消息*/
        while(regist_back != REGIST_OK)
        {
            printf("\t\t\t\t正在注册、、、、稍等！\n");         
            sleep(2);

            /*若返回重名 则注册失败 返回*/
            if(regist_back == MULTI_NAME)
            {   
                return MULTI_NAME;
            }
        }

        printf("\t\t\t\t注册成功！并已帮您登陆！\n");

        msg.state = LINE;          

    }

    printf("\t\t\t\t\033[47;31m 按任意键返回！\033[0m\n");
    getchar();

    return 0;
}
