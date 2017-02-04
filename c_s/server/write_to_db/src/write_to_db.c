/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：write_to_db.c
Author：Jerey_Jobs    Version:0.1    Date:2014.11.23 
Description：将通讯录的数据写入数据库中
Funcion List: NO
*****************************************************/

#include "../../include/myhead.h"

extern sqlite3 *db;
extern char *errmsg;

int write_to_db(LINK buf)    
{
    char str[MAX];
    int rc;
    memset(str,0,sizeof(str));
    
    sprintf(str,"insert into cilent values('%s','%s','%s')",buf->name,buf->id,buf->password);
    
    printf("str:%s\n",str);
        
    rc = sqlite3_exec(db,str,NULL,NULL,&errmsg);    //写入操作

    if(rc)
    {
        printf("insert ERROR!\n");
        printf("rc = %d\n",rc);
    }   

    return 0;
}
