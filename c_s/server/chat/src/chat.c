/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：chat.c
Author：Jerey_Jobs    Version:0.1    Date: 2015.1.22
Description：对用户聊天行为进行处理
Funcion List: int left_msg(MSG buf)
              int chat(int fd,MSG buf)
*****************************************************/

#include "../../include/myhead.h"

extern sqlite3 *db;
extern char *errmsg;
/*************************************************
Function:       int left_msg(MSG buf)
Description:    对不在线的对象进行离线消息处理
Calls:          no
Called By:      int chat(int fd,MSG buf)
Input:          MSG buf 接收的消息
Return:         NO
*************************************************/ 
int left_msg(MSG buf)
{
    /*创建离线消息结点*/
    UNREAD * msg = (UNREAD *)malloc(sizeof(UNREAD));

    strcpy(msg->name,buf.name);
    strcpy(msg->toname,buf.toname);
    strcpy(msg->msg,buf.msg);

    /*头插法插入节点*/
    msg->next = uhead;
    uhead = msg;

    UNREAD *tmp = uhead;

    while(tmp != NULL)
    {
        printf("unread msg |||%s->>%s %s|||||\n",tmp->name,tmp->toname,tmp->msg);

        tmp = tmp->next;
    }

    /*将该离线消息写入数据库*/
    int rc;
    char str[MAX];
    
    memset(str,0,sizeof(str));
    
    sprintf(str,"insert into left_message values ('%s','%s','%s')",buf.name,buf.toname,buf.msg);
    
    printf("str:%s\n",str);
        
    rc = sqlite3_exec(db,str,NULL,NULL,&errmsg);    //写入操作

    /*预防错误*/
    if(rc)
    {
        printf("insert ERROR!\n");
        printf("rc = %d\n",rc);
    }   

}

/*************************************************
Function:       int chat(int fd,MSG buf)
Description:    对聊天行为进行处理
Calls:          NO
Called By:      void *my_read_message(int fd,MSG buf)
Input:          int fd      与客户端连接符
                MSG buf     服务器接收到的消息
Return:         
*************************************************/ 
int chat(int fd,MSG buf)
{
	MSG str = buf;                    //待返回消息

	LINK tmp = head;

	int count = 0;                    //判断对象是否在线

    /*遍历链表找到要聊天的对象 将消息发过去*/
    while(tmp != NULL)
    {
        printf("比较|%s|%s|\n",tmp->name,str.toname);
        if(my_strcmp(tmp->name,str.toname) == 0)
        {   
            /*若该用户在线 则发送消息*/
        	if(tmp->state == LINE)
        	{
        		write(tmp->fd,&str,sizeof(str));
            	printf("%s ->>聊天成功%s  内容 %s\n",str.name,str.toname,str.msg); 
          	    count = LINE;               //发完将count表示在线
        	}
        	else
        	{
        		count = NOTLINE;
        	}
        }
    	tmp = tmp->next;
    }
    
    /*若对方在线 则告诉客户端聊天成功*/
    if(count == LINE)
    {
        str.action = CHAT_OK;
    }
    /*若仍为0 则用户不存在*/
    else if(count == 0)
    {
    	str.action = CHAT_NOT_EXIST;
    }
    /*告诉客户端 对方不在线 消息已离线*/
    else if(count == NOTLINE)
    {
    	str.action = CHAT_NOTLINE;
        left_msg(buf);                    //调用函数将该消息存入离线消息表
    }
    
    write(fd,&str,sizeof(str));

    return 0;
}
