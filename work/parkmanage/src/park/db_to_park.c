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
extern char **result;

int db_to_park()
{
    int i;
    char str[MAX];
    int rc;
    int nrow;
    int ncolumn;

    rc = sqlite3_get_table(db,"select * from car",&result,&nrow,&ncolumn,&errmsg); 

    if(rc)
    {
        printf("not open datebase!\n");
    }
    else
    {
        for(i = 1; i <= nrow; i++)
        {
            top_park++;
            strcpy(park[top_park].num,result[i * ncolumn + 0]);
            park[top_park].park_time = atoi(result[i * ncolumn + 1]);
        }
    }
    
    return 0;
}
