#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

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

int add_car();
int check_putin();
void create_stack();
int display_park();
int get_car();
void menu();
int park_to_way();
int queue_to_park();
int way_to_park();
