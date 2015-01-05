#ifndef _MYHEAD_H_

#define _MYHEAD_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <fcntl.h>
#include <sqlite3.h>

#define portnumber 8000

#define MAX 100

#include <termio.h>


enum CMD{
	LOG = -100,
	REGIST,
	SHOW,
	CHAT,
	BROAD,
	HI,
	CPWD,
	RNAME,
	LOGOFF,
	EXIT,
	KICK,
	BAN,
	RID_PEOPLE,
	LINE,
	NOTLINE,
	CHAT_BAN,
    LOG_OK,
    REGIST_OK,
    CHAT_OK,
    BROAD_OK,
    CPWD_OK,
    RNAME_OK,
    LOGOFF_OK

};

enum B{
	YES = -1000,
	NOT_EXIST,
	PASSWORD_ERROR,
	CHAT_NOT_EXIST,
	CHAT_NOTLINE,
	BAN_OK,
	BAN_NOTLINE,
	BAN_NOTEXIST,
	KICK_OK,
	KICK_NOTLINE,
	KICK_NOTEXIST,
	KICKED,
	BANED,
	RID_OK,
	RIDED,
	RID_NOTLINE,
	RID_NOTEXIST,
	SHOW_OK,
	SHOW_BACK,
	HI_OK,
	HI_1 = 100,
	HI_2,
	HI_3,
	HI_4,
	HI_5,
	HI_6
};

struct message
{
    int action;
    char id[20];
    char name[20];
    char password[20];
    char toname[20];
    char msg[100];
    int state;
};

typedef struct message MSG;

MSG msg;
int sockfd;


int regist_back;



#endif
