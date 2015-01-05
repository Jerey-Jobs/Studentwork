/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include "../../include/myhead.h"


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
}



int regist(int fd,MSG buf)
{
	LINK newnode = (LINK)malloc(sizeof(NODE));
 
    int tmp_id;
    char id_str[20];

    newnode->fd = fd;
	strcpy(newnode->name,buf.name);
	strcpy(newnode->password,buf.password);

    srand((unsigned)time(NULL));  
    
    tmp_id = rand()%1000000;            //初始化新联系人的ID

    my_itoa(tmp_id,id_str);

    strcpy(newnode->id,id_str);

    newnode->state = LINE;

    write_to_db(newnode);
    
    newnode->next = head;
    head = newnode;

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
    
    return 0;
}
