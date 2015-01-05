/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
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

    for(i = 0; i <= top_park; i++)
    {
        sprintf(str,"insert into car values ('%s','%d')",park[i].num,park[i].park_time);
    
        printf("file : %s\n",str);

        rc = sqlite3_exec(db,str,NULL,NULL,&errmsg); 
    }

    return 0;
}
