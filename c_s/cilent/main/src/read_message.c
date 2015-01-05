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
    int fd = *((int *)arg);
     
    int count;
    char buffer[1024];
    struct message r_buf;
      
    while(1)
    {
        memset(&r_buf,0,sizeof(r_buf));

	    if((count = read(fd,&r_buf,sizeof(r_buf))) > 0)
        {
     //   	printf("action = %d  ",r_buf.action);
            printf("\n");      
            switch(r_buf.action){

            case REGIST_OK:
            {
                regist_back = REGIST_OK;
                printf("您获得靓号ID  %s\n",r_buf.id);
                break;
            }

            case LOG_OK:
            {
                msg.state = LINE;
                strcpy(msg.name,r_buf.name);
                printf("登陆成功。。\n");
                break;
            }

            case NOT_EXIST:
            {
                printf("用户不存在。。。\n");
                break;
            }

            case PASSWORD_ERROR:
            {
                printf("密码错误。。。\n");
                break;
            }

            case CHAT:
            {
                printf("%s 对您大吼: %s\n",r_buf.name,r_buf.msg);
                break;
            }

            case CHAT_OK:
            {
                printf("发送成功。。\n");
                break;
            }

            case CHAT_NOT_EXIST:
            {
                printf("聊天对象还没注册哦、、、\n");
                break;
            }

            case CHAT_NOTLINE:
            {  
                printf("聊天对象还未上线哦、、、\n"); 
                break;
            }
 
            case BROAD_OK:
            {
                printf("广播成功咯。。\n");
                break;
            }

            case BROAD:
            {
                printf("%s 对大家大吼一声 : %s\n",r_buf.name,r_buf.msg);
                break;
            }

            case RNAME_OK:
            {
                printf("修改名称成功！！\n");
                break;
            }

            case CPWD_OK:
            {
                printf("修改密码成功！！！\n");
                break;
            }

            case LOGOFF_OK:
            {
                printf("下线成功！！\n");
                break;
            }
            case BAN_OK:
            {
                printf("禁言成功！！\n");
                break;
            }           
            case BAN_NOTLINE:
            {
                printf("禁言对象不在线！！\n");
                break;
            }
            case BAN_NOTEXIST:
            {
                printf("禁言对象不存在！！\n");
                break;
            }
            case KICK_OK:
            {
                printf("踢人成功，对方已被强制下线！！\n");
                break;
            }

            case KICK_NOTLINE:
            {
                printf("对方不在线，踢人失败！！\n");
                break;
            }

            case KICK_NOTEXIST:
            {
                printf("对方不存在，踢人失败！！\n");
                break;
            }

            case BANED:
            {
                msg.state = CHAT_BAN;
                printf("您已被管理员禁言，将不能发送任何聊天！\n");
                break;
            }

            case KICKED:
            {
                msg.state = NOTLINE;
                printf("您已被管理员踢出聊天房间！\n");
                break;
            }

            case RIDED:
            {
                msg.state = LINE;
                printf("您已被管理员解除禁言\n");
                break;
            }

            case RID_OK:
            {
                printf("解除禁言成功！\n");
                break;
            }

            case RID_NOTLINE:
            {
                printf("您解除的对象已不在线。。\n");
                break;
            }

            case RID_NOTEXIST:
            {
                printf("您解除的对象不存在。。\n");
                break;
            }
            
            case SHOW_BACK:
            {
                printf("当前在线：%s\n",r_buf.toname);
                break;
            }

            case HI_OK:
            {
                printf("快捷表情发送成功！\n");
                break;
            }

            case HI_1:
            {
                printf("%s 对大家做了个表情  →_→  (怀疑)\n",r_buf.name);
                break;
            }

            case HI_2:
            {
                printf("%s 对大家做了个表情  >_<|||   (尴尬)\n",r_buf.name);
                break;
            }
            case HI_3:
            {
                printf("%s 对大家做了个表情  O(∩_∩)O   (微笑)\n",r_buf.name);
                break;
            }

            case HI_4:
            {
                printf("%s 对大家做了个表情  （＋﹏＋）  (感动)\n",r_buf.name);
                break;
            }

            case HI_5:
            {
                printf("%s 对大家做了个表情  (*^﹏^*)    (羞涩)\n",r_buf.name);
                break;
            }

            case HI_6:
            {
                printf("%s 对大家做了个表情 大骂 (((m -_-)mb (什么龟)\n",r_buf.name);
                break;
            }




            }

             
        }
    }

}
