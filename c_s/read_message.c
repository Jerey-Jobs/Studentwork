/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

void *read_message(void *arg)
{ 
    int fd = (int)arg;

    printf("get! readmessage\n");
    int count;
    MSG buf;
    
    if((count = read(fd,&buf,sizeof(buf))) != 0)
    {
        printf("get!\n");

        printf("get ");

        printf("action = %d  ",buf.action);
        printf(" id = %s",buf.id);
        printf("  name = %s",buf.name);
        printf("  password = %s",buf.password);
        printf("  toname =%s",buf.toname);
        printf("  msg = %s",buf.msg);
        printf("  state = %d",buf.state);

        switch(buf.action)
        {
        	case LOGIN:
            case REGISTER:
        	case CHAT:
        	case BROADCAST:
        	case CHANGE_PASSWD:
        	case LOG_OUT:
        	case CHANGE_NAME://printf("CHANGE_NAME\n");
            case KICK:
            case BAN:
            default: break;
        }

    }

    printf("read end !!!!!!!\n");    
}
