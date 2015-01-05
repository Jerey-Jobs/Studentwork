/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：write_to_file.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/11/23
Description：将文件写入数据库
Funcion List: no
*****************************************************/

#include "../../include/myhead.h"

extern sqlite3 *db;
extern int top_park;
extern char *errmsg;

int write_to_file()
{
    int i;
    char str[MAX];
    int rc;

    rc = sqlite3_exec(db,"delete from car",0,0,&errmsg);   //导入数据前先清空数据库

    /*将停车栈里的所有数据存进数据库*/
    for(i = 0; i <= top_park; i++)
    {
        sprintf(str,"insert into car values ('%s','%d')",park[i].num,park[i].park_time);

        rc = sqlite3_exec(db,str,NULL,NULL,&errmsg); 
    }

    return 0;
}
