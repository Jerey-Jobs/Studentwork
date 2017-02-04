/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：regist.c
Author：Jerey_Jobs    Version:0.1    Date:2015.1.22 
Description：对客户端注册行为进行操作
Funcion List: int my_itoa(int num,char *str)
             int regist(int fd,MSG buf)
*****************************************************/

#include "../../include/myhead.h"

/*************************************************
Function:      int my_itoa(int num,char *str) 
Description:   将生成的随机数转成字符串
Calls:         NO
Called By:     int regist(int fd,MSG buf)
Input:         int num 随机数
               char str 传出参数 字符串 
Return:        0
*************************************************/ 
int my_itoa(int num,char *str)
{
    int power;                    //权
    int flag = num;               //临时变量

    /*eg: flag = 123  =>  power = 100*/
    for(power = 1; flag >= 10; flag = flag / 10)
    {
        power = power * 10;
    }
    /*eg: 123 / 100 = 1 ; 123 % 100 = 23; 23 / 10 = 2*/
    for( ;power > 0; power = power / 10)
    {
        *str = num / power + '0';  // 1 + '0' = '1' 
        num = num % 10;
        str++;
    }
    *str = '\0';
    
    return 0;
}


/*************************************************
Function:       int regist(int fd,MSG buf)
Description:    对客户端注册行为进行操作
Calls:          int my_itoa(int num,char *str)
Called By:      void *my_read_message(int fd,MSG buf)
Input:          int fd    连接套接字
                MSG buf   接收到的消息
Return:         no
*************************************************/
int regist(int fd,MSG buf)
{
    /*创建新用户节点*/
	LINK newnode = (LINK)malloc(sizeof(NODE));
 
    int tmp_id;          //新用户id
    char id_str[20];

    MSG regist_msg;

    LINK tmp_name = head;

    /*遍历用户信息链表看是否重复注册*/
    while(tmp_name != NULL)
    {
        if(my_strcmp(tmp_name->name,buf.name) == 0)
        {
            regist_msg.action = MULTI_NAME;
            write(fd,&regist_msg,sizeof(regist_msg));
            
            printf("用户名重复注册\n");
            return MULTI_NAME;
        }
        tmp_name = tmp_name->next;
    }

    /*将新用户数据存进结点*/
    newnode->fd = fd;
	strcpy(newnode->name,buf.name);
	strcpy(newnode->password,buf.password);

    srand((unsigned)time(NULL));        //生成id  
    
    tmp_id = rand()%1000000;            //初始化新联系人的ID

    my_itoa(tmp_id,id_str);             //将id转成字符串

    strcpy(newnode->id,id_str);

    newnode->state = LINE;              //注册后帮用户登录

    write_to_db(newnode);               //将新用户信息写入数据库
    
    /*将新用户信息插入链表*/
    newnode->next = head;
    head = newnode;

    /*告诉新用户注册成功*/
    MSG str;

    str.action = REGIST_OK;
    strcpy(str.id,id_str);
    str.state = LINE;

    write(fd,&str,sizeof(str));

    LINK tmp = head;

    while(tmp != NULL)
    {
    	printf("#####、id %s  name %s state %d \n",tmp->id,tmp->name,tmp->state);

    	tmp = tmp->next;
    }

    sleep(3);

    LINK temp = head;

        while(temp != NULL)
        {
            memset(&str,0,sizeof(str));

            if(temp->fd == fd)
            {
                temp = temp->next;
                continue;
            }

            if(temp->state == LINE)
            {
                str.action = CILENT_CHANGE;
                
                usleep(1000);

                write(temp->fd,&str,sizeof(str));             
            }

            temp = temp->next;
        }
    
    return 0;
}
