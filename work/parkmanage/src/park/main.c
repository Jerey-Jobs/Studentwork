/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：      main.c
Author：Jerey_Jobs    Version:0.1    Date: 2014.11.23
Description： 停车场系统主函数
Funcion List: void create_stack()
              void menu()  
*****************************************************/

#include "../../include/myhead.h"

int top_park;
int top_way;
int front;
int tail;    

sqlite3 *db = NULL;
char *errmsg;
char **result;

int main()
{
    int rc;

    rc = sqlite3_open("test.db",&db);
    
    rc = sqlite3_exec(db,"create table car (name text,time integer)",0,0,&errmsg);

    create_stack();          //初始化栈、队列

    db_to_park();

    rc = sqlite3_exec(db,"delete from car",0,0,&errmsg);

    menu();                  //调用主界面函数

    return 0;
}
