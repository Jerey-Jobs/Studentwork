/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：login.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.20 
Description：对客户端登陆操作进行处理的函数
Funcion List: int check_people(char *id,char *password);
              int find_name(char *id,char *name);
*****************************************************/

#include "../../include/myhead.h"

extern sqlite3 *db;
extern char *errmsg;
extern char **result;

/*************************************************
Function:       int check_people(char *id,char *password)
Description:    检查用户id和密码是否正确
Calls:          NO
Called By:      login.c
Input:          char *id        用户id
                char *password  用户密码
Return:         YES             id和密码正确
                NO              密码不正确
                NOT_EXIST       不存在用户
*************************************************/ 
int check_people(char *id,char *password)
{
	LINK tmp = head;

	while(tmp != NULL)
	{
		if(my_strcmp(tmp->id,id) == 0)
		{
			if(my_strcmp(tmp->password,password) == 0)
			{
			    return YES;
			}
			else
			{
				return PASSWORD_ERROR;
			}
		}

		tmp = tmp->next;
	}

	return NOT_EXIST;

}

/*************************************************
Function:       int find_name(char *id,char *name);
Description:    根据id找出该用户的姓名存入name中
Calls:          NO
Called By:      login.c
Input:          char *id     用户id
                char *name   用户姓名(传出参数)
Return:         No
*************************************************/ 
int find_name(char *id,char *name)
{
	LINK tmp = head;

    /*遍历链表找出该id对应的用户姓名*/
	while(tmp != NULL)
	{
		if(my_strcmp(tmp->id,id) == 0)
		{
			strcpy(name,tmp->name);
			return 0;
		}
		tmp = tmp->next;
	}
    return 0;
}

/*************************************************
Function:       int login(int fd,MSG buf)
Description:    用户登录主函数
Calls:          int check_people(char *id,char *password)
                int find_name(char *id,char *name)
Called By:      void *my_read_message(int fd,MSG buf)
Input:          int fd    连接套接字
                MSG buf   接收到的消息
Return:         NO
*************************************************/ 
int login(int fd,MSG buf)
{
	MSG msg = buf;
	MSG str;

	LINK temp = head;

	int ret = check_people(msg.id,msg.password);    //判断用户id和密码是否正确

    /*若id和密码正确 则告诉客户端上线成功*/
	if(ret == YES)
	{
        while(temp != NULL)
        {
		    if(my_strcmp(temp->id,msg.id) == 0)
		    {
		    	temp->state = LINE;                  //将用户信息链表中的该用户状态改为在线
                temp->fd = fd;                       

		    	printf("客户端上线成功。。\n");

                str.action = LOG_OK;
                strcpy(str.name,temp->name);

                write(fd,&str,sizeof(str));
		    	
		    	break;
		    }

        	temp = temp->next;
        }
	}

    /*若该用户密码错误 则告诉用户密码错误*/
	else if(ret == PASSWORD_ERROR)
	{
        str.action = PASSWORD_ERROR;
        printf("客户密码错误。。\n");
        write(fd,&str,sizeof(str));      
	}

    /*告诉用户不存在请重新输入*/
	else if(ret == NOT_EXIST)
	{
        printf("客户不存在。。\n");
        str.action = NOT_EXIST;
        write(fd,&str,sizeof(str));
	}

    temp = head;

	while(temp != NULL)
    {
    	printf("####、id %s  name %s  state %d   ####\n",temp->id,temp->name,temp->state);

    	temp = temp->next;
    }

    UNREAD *tmp = uhead;

    while(tmp != NULL)
    {
        printf("unread msg |||%s->>%s %s|||||\n",tmp->name,tmp->toname,tmp->msg);

        tmp = tmp->next;
    }

    UNREAD *unread_tmp = uhead;
    memset(&str,0,sizeof(msg));

    char cilent_name[20];

    find_name(msg.id,cilent_name);            //找到该用户的名字

    /*遍历离线消息表 若存在离线消息则发送*/
    while(unread_tmp != NULL)       
    {
        /*若存在改用户离线消息则发送*/
        if(my_strcmp(unread_tmp->toname,cilent_name) == 0)
        {
            str.action = LEFT_MSG;
            strcpy(str.name,unread_tmp->name);
            strcpy(str.toname,unread_tmp->toname);
            strcpy(str.msg,unread_tmp->msg);
            
            sleep(2);
            write(fd,&str,sizeof(str));
            printf("left msg send ok%s|%s|%s\n",str.name,str.toname,str.msg);
        }

        unread_tmp = unread_tmp->next;
    }

    /*发送完毕将该用户在离线消息表中的离线消息全部删除*/
    unread_tmp = uhead;

    if(unread_tmp != NULL)
    {    
        if(my_strcmp(unread_tmp->toname,cilent_name) == 0)
        {
            uhead = uhead->next;
        }
        
        if(uhead != NULL)
        {
            unread_tmp = uhead;
            UNREAD *unread_next = unread_tmp->next;
        
            while(unread_tmp != NULL && unread_tmp->next != NULL)
            {
                if(my_strcmp(unread_next->toname,cilent_name) == 0)
                {
                    unread_tmp->next = unread_next->next;
                    free(unread_next);
                }   

                unread_tmp = unread_next;
                unread_next = unread_next->next;
            }
        }
    }

    /*将其在数据库离线表中的数据也全部删除*/
    int rc;
    char ptr[MAX];

    memset(ptr,0,sizeof(ptr));
    
    sprintf(ptr,"delete from left_message where toname = '%s'",cilent_name);
    
    printf("str:%s\n",ptr);
        
    rc = sqlite3_exec(db,ptr,NULL,NULL,&errmsg);    //写入操作

    if(rc)
    {
        printf("insert ERROR!\n");
        printf("rc = %d\n",rc);
    }   
    
    sleep(1);
    /*若存在该 用户同时通知所有在线的用户 该用户上线了*/
    if(ret == YES)
    {    
        temp = head;

        while(temp != NULL)
        {
            memset(&str,0,sizeof(str));

            if(temp->state == LINE)
            {
                str.action = CILENT_CHANGE;                
                usleep(1000);

                write(temp->fd,&str,sizeof(str));             
            }

            temp = temp->next;
        }
    }

    return 0;
}

