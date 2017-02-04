/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：read_message.c
Author：Jerey_Jobs    Version:0.1    Date:2015/1/18 
Description：客户端负责接收消息的线程
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"

void *read_message(void *arg)
{
    int fd = *((int *)arg);                //获得连接套接字
    int count;                             //接收到的实际字符数
    
    char write_buf[MAX];                   //写入文件缓冲
    
    struct message r_buf;                  //接收缓冲区
   
    while(1)
    {
       // sleep(1);
        memset(&r_buf,0,sizeof(r_buf));

	    if((count = read(fd,&r_buf,sizeof(r_buf))) > 0)              //接收到字符才执行
        {
            /*检查chat聊天窗口是否满*/
            
            mvwprintw(tips_win, 1, 1, "                                                       ");
            /*根据接收到的相应的动作定义执行相应操作*/        
            switch(r_buf.action)
            {
                case REGIST_OK:                       
                {
                    regist_back = REGIST_OK;
                    printf("\t\t\t\t您获得靓号ID  %s\n",r_buf.id);
                    break;
                }

                case MULTI_NAME:
                {
                    regist_back = MULTI_NAME;
                    printf("\t\t\t\t该用户名已经注册\n");
                    printf("\t\t\t\t请重新注册、、、、\n");
                    break;
                }

                case LOG_OK:
                {
                    msg.state = LINE;
                    strcpy(msg.name,r_buf.name);
                    printf("\t\t\t\t登陆成功。。\n");
                    break;
                }

                case NOT_EXIST:
                {
                    printf("\t\t\t\t用户不存在。。。\n");
                    break;
                }

                case PASSWORD_ERROR:
                {
                    printf("\t\t\t\t密码错误。。。\n");
                    break;
                }

                case CHAT:                            //收到消息打印出提示并将消息写入聊天记录
                {
                    my_gettime();
                    wprintw(chat_win, ">>>%s %s talk to you : %s\n",c_time,r_buf.name,r_buf.msg);
                    wrefresh(chat_win);
                    
                    memset(write_buf,0,sizeof(write_buf));
                    sprintf(write_buf, ">>>%s %s talk to you : %s",c_time,r_buf.name,r_buf.msg);
                    write_line(write_buf);

                    break;
                }

                case LEFT_MSG:                       //收到离线消息打印提示并写入文件
                {
                    wprintw(chat_win, ">>>there is a unread message\n");
                    wprintw(chat_win, ">>>unread message: %s talk to you : %s\n",r_buf.name,r_buf.msg);
                    wrefresh(chat_win);

                    memset(write_buf,0,sizeof(write_buf));
                    sprintf(write_buf, "unread message: %s talk to you : %s",r_buf.name,r_buf.msg);
                    write_line(write_buf);
                    break;
                }

                case CHAT_OK:
                {
                    mvwprintw(tips_win, 1 , 2 , "chat send ok");
                    wrefresh(tips_win);
             //     printf("发送成功。。\n");
                    break;
                }

                case CHAT_NOT_EXIST:
                {
                    mvwprintw(tips_win, 1 , 2 , "the man haven't regist !!!");
                    wrefresh(tips_win);
              //      printf("聊天对象还没注册哦、、、\n");
                    break;
                }

                case CHAT_NOTLINE:
                {  
                    mvwprintw(tips_win, 1 , 2 , "the man isn't online,the msg have been left!");
                    wrefresh(tips_win);
               //     printf("聊天对象还未上线哦、、、\n"); 
                    break;
                }
     
                case BROAD_OK:
                {
                    mvwprintw(tips_win, 1 , 2 , "broad ok !!!");
                    wrefresh(tips_win);
               //     printf("广播成功咯。。\n");
                    break;
                }

                case BROAD:
                {
                    my_gettime();
                    wprintw(chat_win, ">>>%s %s broadcast that : %s\n",c_time,r_buf.name,r_buf.msg);
                    wrefresh(chat_win);
                    
                    memset(write_buf,0,sizeof(write_buf));
                    sprintf(write_buf, "%s %s broadcast that: %s",c_time,r_buf.toname,r_buf.msg);
                    write_line(write_buf);                   
                  //  printf("%s 对大家大吼一声 : %s\n",r_buf.name,r_buf.msg);
                    break;
                }

                case RNAME_OK:
                {
                    mvwprintw(tips_win, 1 , 2 , "change name ok !!!");
                    wrefresh(tips_win);
                //    printf("修改名称成功！！\n");
                    break;
                }

                case CPWD_OK:
                {
                    mvwprintw(tips_win, 1 , 2 , "change password ok !!!");
                    wrefresh(tips_win);
                  //  printf("修改密码成功！！！\n");
                    break;
                }

                case LOGOFF_OK:
                {
                    
                    break;
                }

                case SHOW_BACK:
                {
                    mvwprintw(show_win, line_show++, 4 , "%s    ",r_buf.toname);
                    wrefresh(show_win);

                    break;
                }

                case BAN_OK:
                {
                    mvwprintw(tips_win, 1 , 2 , "ban ok !!!");
                    wrefresh(tips_win);
                 //   printf("禁言成功！！\n");
                    break;
                }

                case BAN_NOTLINE:
                {
                    mvwprintw(tips_win, 1 , 2 , "ban person isn't online!!!");
                    wrefresh(tips_win);
                 //   printf("禁言对象不在线！！\n");
                    break;
                }

                case BAN_NOTEXIST:
                {
                    mvwprintw(tips_win, 1 , 2 , "ban person isn't exist");
                    wrefresh(tips_win);
                  //  printf("禁言对象不存在！！\n");
                    break;
                }

                case KICK_OK:
                {
                    mvwprintw(tips_win, 1 , 2 , "kick person OK!!!");
                    wrefresh(tips_win);
                 //   printf("踢人成功，对方已被强制下线！！\n");
                    break;
                }

                case KICK_NOTLINE:
                {
                   
                    mvwprintw(tips_win, 1 , 2 , "kick person isn't online!!!");
                    wrefresh(tips_win);
                 //   printf("对方不在线，踢人失败！！\n");
                    break;
                }

                case KICK_NOTEXIST:
                {
                    mvwprintw(tips_win, 1 , 2 , "kick person isn't exist");
                    wrefresh(tips_win);
                 //   printf("对方不存在，踢人失败！！\n");
                    break;
                }

                case BANED:
                {
                    msg.state = CHAT_BAN;
                    mvwprintw(tips_win, 1 , 2 , "you are baned by admin,you can't chat ");
                    wrefresh(tips_win);
                 //   printf("您已被管理员禁言，将不能发送任何聊天！\n");
                    break;
                }

                case KICKED:
                {
                    mvwprintw(tips_win, 1 , 2 , "you are kicked ");
                    wrefresh(tips_win);
                    refresh();
                  
                    endwin();

                    msg.state = NOTLINE;

                    system("clear");
                    printf("\n\n\n\n你已被管理员踢出房间！！！");
                    
                    exit(1);
                //    printf("您已被管理员踢出聊天房间！\n");
                    break;
                }

                case RIDED:
                {
                    msg.state = LINE;
                    mvwprintw(tips_win, 1 , 2 , "the admin allow you chat now ");
                    wrefresh(tips_win);
               //     printf("您已被管理员解除禁言\n");
                    break;
                }

                case RID_OK:
                {
                    mvwprintw(tips_win, 1 , 2 , "rid person ok!! ");
                    wrefresh(tips_win);
                //    printf("解除禁言成功！\n");
                    break;
                }

                case RID_NOTLINE:
                {
                    mvwprintw(tips_win, 1 , 2 , "the person isn't online ");
                    wrefresh(tips_win);
                 //   printf("您解除的对象已不在线。。\n");
                    break;
                }

                case RID_NOTEXIST:
                {  
                    mvwprintw(tips_win, 1 , 2 , "the person isn't exist ");
                    wrefresh(tips_win);
                //    printf("您解除的对象不存在。。\n");
                    break;
                }

                case SEND_FILE:                    //对方发文件来 打开文件并在后面追加一行
                {
                    my_gettime();
                    mvwprintw(tips_win, 1 , 2 , "%s %s send file %s to you",c_time,r_buf.name,r_buf.file_name);
                    wrefresh(tips_win);
                    
                    if((fp = fopen(r_buf.file_name,"a+")) == NULL)
                    {
                        mvwprintw(tips_win, 1, 2, "                                                   ");
                        mvwprintw(tips_win, 1 , 2 , "open file error");
                        wrefresh(tips_win);
                    }
                    
                    fputs(r_buf.msg,fp);

                 //   fputc('\n',fp);

                    fclose(fp);

                    break;
                }

                case SEND_OK:
                {  
                    mvwprintw(tips_win, 1 , 2 , "send OK!! ");
                    wrefresh(tips_win);
                    break;
                }
                case SEND_NOT_EXIST:
                {                      
                    mvwprintw(tips_win, 1, 2 , "the person isn't exist");
                    wrefresh(tips_win);
                    break;
                }
                case SEND_NOTLINE:
                {  
                    mvwprintw(tips_win, 1 , 2 , "the person is not online");
                    wrefresh(tips_win);
                    break;
                }

                case ADS_OK:
                {  
                    mvwprintw(tips_win, 1 , 2 , "Advertise ok!!");
                    wrefresh(tips_win);
                    break;
                }

                case ADS:
                {  
                    strcpy(ads_buf,r_buf.msg);

                    break;
                }

                case CILENT_CHANGE:
                {
                    show();
                    break;
                }



                /*
                
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

                */


            }

            clear_flag = CLEAR_START;
        }
    }

}
