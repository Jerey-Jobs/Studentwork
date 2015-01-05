/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

extern int power;

int cilent_log()
{
    
    char passwd[20];
    int i;

	msg.action = LOG;
	printf("   ID : ");
	scanf("%s",msg.id);
	printf("密 码 ：");
	getchar();
    for(i = 0; i < 20; i++)
    {
        passwd[i] = my_getch();
       
        if(passwd[i] == '\r')
        {
        	passwd[i] = '\0';
        	break;
        }
        printf("*");
    }
    printf("\n");

    strcpy(msg.password,passwd);

    if(my_strcmp(msg.id,"10000") == 0)
    {
        if(my_strcmp(passwd,"admin") == 0)
        {
            strcpy(msg.name,"the big admin");
            msg.state = LINE;
            power = 1;
        }
    }

	if(write(sockfd,&msg,sizeof(msg))==-1) 
	{ 
        fprintf(stderr,"log write Error:%s\n",strerror(errno)); 
    }
    
    printf("log send ok!");
    printf("\t\t\033[47;31m 按任意键返回！\033[0m\n");
    getchar();


    return 0;
}
