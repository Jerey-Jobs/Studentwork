
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define SUCCESS 0
#define FAIL -1
#define ERROR 2

#define MAX 100


struct people
{
    int num;
    char name[MAX];
    char phonenum[MAX];
    char address[MAX];
    char homephone[MAX];

    struct people *next;    
};

typedef struct people NODE;
typedef NODE * LINK;


int check_putin(LINK *head);
void menu(LINK *head);
int my_add(LINK *head);
int my_strcmp(char *str,char *ptr);
int my_delete(LINK *head);
void create_list(LINK *head);
int my_search(LINK *head);
void my_display(LINK *head);
