#include <stdio.h>

#include <sqlite3.h>

int main()
{
    int id;
    int rc;
    char *errmsg;
    char name[100];
    char sql[1024];
    sqlite3 *db;
    
    rc = sqlite3_open("test.db",&db);

    if(rc)
    {
        printf("sqlite open fail!\n");
	exit(1);
    }

    scanf("%d",&id);
    scanf("%s",name);

    sprintf(sql,"insert into student(id,name) values(%d,'%s')",id,name);

    printf("%s\n",sql);

    sqlite3_exec(db,"create table student(id integer primary key,name text)",NULL,NULL,&errmsg);

    sqlite3_exec(db,sql,NULL,NULL,&errmsg);

    sqlite3_close(db);

    return 0;
}
