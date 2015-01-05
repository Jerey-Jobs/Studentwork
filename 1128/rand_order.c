/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>

#define LEN 100
#define MAX 10
#define ERROR 1

int num_to_file(FILE *fp)
{
    int i;
    int num;
    char str[LEN];
    
    for(i = 0; i < MAX; i++)
    {
        num = rand()%1000;
        
        memset(str,0,sizeof(str));
        
        sprintf(str,"%d \0",num);
        
        fwrite(str,1,strlen(str),fp);
    }    
}

int file_to_num(FILE *fp,int *num)
{
    int i;
    char str[LEN];
    char *tmp = NULL;

    fgets(str,sizeof(str),fp);
  
    tmp = strtok(str," ");

    *num = atoi(tmp);

    for(i = 1; i < MAX ; i++)
    {
        tmp = strtok(NULL," ");
        *(num + i) = atoi(tmp);
    }
}

int order_num(int *num)
{
    int i;
    int j;
    int tmp;

    for(i = 0; i < MAX - 1; i++)
    {
        for(j = 0; j < MAX - 1 - i; j++)
        {
            if(*(num + j) > *(num + j + 1))
            {
                tmp = *(num + j);
                *(num + j) = *(num + j + 1);
                *(num + j + 1) = tmp;
            }
        }
    }
}

int order_to_file(FILE *fp,int *num)
{
    int i;
    char str[LEN];
    
    for(i = 0; i < MAX; i++)
    {   
        memset(str,0,sizeof(str));
        
        sprintf(str,"%d \0",*(num + i));
        
        fwrite(str,1,strlen(str),fp);
    }

}

int main()
{
    int i;
    int num[MAX];
    char str[LEN];
    FILE *fp;

    fp = fopen("number","w+");

    if(fp == NULL)
    {
        printf("fopen file error !\n");
        exit(ERROR);
    }
 
    num_to_file(fp);

    fseek(fp,0,SEEK_SET);
    fgets(str,LEN,fp);
    printf("the old num : %s\n",str);

    fseek(fp,0,SEEK_SET);
    file_to_num(fp,num);
    
    order_num(num);

    fseek(fp,0,SEEK_SET);
    order_to_file(fp,num);

    fseek(fp,0,SEEK_SET);
    fgets(str,LEN,fp);
    printf("the ordering num : %s\n",str);

    return 0;
}
