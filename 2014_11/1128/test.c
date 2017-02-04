/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <sqlite3.h>

static sqlite3 *db = NULL;
static char *errmsg = NULL;
static char **result = NULL;

int main()
{
    int rc;

    rc = sqlite3_open("test.db",&db);
    rc = sqlite3_exec(db,"create table stu (id integer primary key,name text,sex text,key integer)",0,0,&errmsg);
    rc = sqlite3_exec(db,"insert into stu values('4','dab','male',24)",0,0,&errmsg);

    if(rc)
    {
        printf("not open datebase!\n");
    }
    else
    {
        printf("exec success!\n");   
    }

    int i;
    int j;
    int nrow;
    int ncolumn;

    rc = sqlite3_get_table(db,"select * from stu",&result,&nrow,&ncolumn,&errmsg);
   
    if(rc)
    {
        printf("query fail!\n");
    }
    else
    {
        for(i = 1; i <= nrow ;i++)
        {
            for(j = 0; j <= ncolumn; j++)
            {
                printf("%5s |",result[i*ncolumn + j]);
            }

            printf("\n");
        }
    }

    sqlite3_free_table(result);

    sqlite3_close(db);

    return 0;
}
