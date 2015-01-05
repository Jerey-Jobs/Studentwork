#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

#define MAX 100

enum STACK{PARK_EMPTY = -100,WAY_EMPTY,IN_PARK,IN_QUEUE,NOT_EXIST,YES,NO,TO_WAY_OK,};

struct car
{
    char num[MAX];
    
    int park_time;
};

typedef struct car NODE;

NODE park[10];
NODE way[10];
NODE queue[MAX];

int top_park;                   //停车厂车的数量
int top_way;
int front;
int tail;

int add_car(int fd);
int check_putin(int fd);
void create_stack();
int display_park(int fd);
int get_car(int fd);
void menu(int fd);
int park_to_way();
int queue_to_park();
int way_to_park();
int write_line(int fd,char *buf,int len);
