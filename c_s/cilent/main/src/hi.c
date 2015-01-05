/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

int hi()
{

    if(msg.state == CHAT_BAN)
    {
        printf("您已被禁言 无法发言!!\n");
        printf("\t\t\033[47;31m 按任意键返回！\033[0m\n");
        getchar();
        return CHAT_BAN;
    }


    msg.action = HI;

    system("clear");
    printf("\t\t\033[47;31m 请选择表情！                \033[0m\n");
    printf("\t\t\033[47;31m 1. →_→       2.>_<|||       \033[0m\n");
    printf("\t\t\033[47;31m 3. O(∩_∩)O   4.（＋﹏＋）   \033[0m\n");
    printf("\t\t\033[47;31m 5. (*^﹏^*)  6. (((m -_-)mb \033[0m\n");
    
    int num;

    scanf("%d",&num);

    switch(num)
    {
    	case 1:strcpy(msg.msg,"doubt");break;
    	case 2:strcpy(msg.msg,"embrass");break;
    	case 3:strcpy(msg.msg,"happy");break;
    	case 4:strcpy(msg.msg,"touching");break;
    	case 5:strcpy(msg.msg,"xiushe");break;
    	case 6:strcpy(msg.msg,"shenmegui");break;
    	default :printf("输入错误，请重新输入！");
    	         getchar();
    	         hi();
    	         break;
    }

    if(write(sockfd,&msg,sizeof(msg)) == -1) 
	{
        fprintf(stderr,"regist write Error:%s\n",strerror(errno)); 
    }
    
    printf("hi ok\n");
    
    printf("\t\t\033[47;31m 按任意键返回！\033[0m\n");
    getchar();
    getchar();

    return 0;
}
