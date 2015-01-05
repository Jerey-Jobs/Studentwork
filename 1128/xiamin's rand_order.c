/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 100                   //字符串长度
#define MAX 10                    //数组长度
#define ERROR 1
#define SUCCESS 2

/*生成10个随机数，并存放到文件中*/
int num_to_file(FILE *fp)
{
    int i;                   
    int num;                      //存放随机数
    char str[LEN];
    
    /*生成10个随机数，并存放到文件中*/
    for(i = 0; i < MAX; i++)
    {
        num = rand()%1000;
        
        memset(str,0,sizeof(str));
        
        sprintf(str,"%d \0",num);           //将num转换成str格式存放在str字符串中  
        
        fwrite(str,1,strlen(str),fp);       //将str写入文件
    } 

    return SUCCESS;   
}

/*读出文件中的10个数，并放入整形数组中*/
int file_to_num(FILE *fp,int *num)
{
    int i;
    char str[LEN];                //文件中读出的字符串
    char *tmp = NULL;

    fread(str,1,sizeof(str),fp);    //读出文件中所有数
  
    tmp = strtok(str," ");            //将第一个空格前的字符串找出

    *num = atoi(tmp);                 //字符串转整形，赋值给数组

    for(i = 1; i < MAX ; i++)         //第二个到第10个数挨个找出
    {
        tmp = strtok(NULL," ");   
        *(num + i) = atoi(tmp);       //挨个赋值给数组
    }

    return SUCCESS;
}

/*冒泡法对数组排序*/
int order_num(int *num)
{
    int i;
    int j;
    int tmp;

    /*冒泡法排序，小的在前*/
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

    return SUCCESS;
}

/*排序后的数组转换成字符串并存入文件中*/
int order_to_file(FILE *fp,int *num)
{
    int i;
    char str[LEN];
    
    /*将数组数挨个转换成字符串并写入文件中*/
    for(i = 0; i < MAX; i++)
    {   
        memset(str,0,sizeof(str));
        
        sprintf(str,"%d \0",*(num + i));   //格式转换整形变成字符串并加空格
        
        fwrite(str,1,strlen(str),fp);      
    }
    return SUCCESS;
}

int main()
{
    int i;
    int num[MAX];                            //存放10个数
    char str[LEN];                           //读取，写入文件缓冲
    FILE *fp;                                //文件指针

    fp = fopen("number","w+");

    if(fp == NULL)
    {
        printf("fopen file error !\n");
        exit(ERROR);
    }
 
    num_to_file(fp);                         //将数写入文件

    fseek(fp,0,SEEK_SET);
    fgets(str,LEN,fp);
    printf("the old num : %s\n",str);        //打印出文件内容

    fseek(fp,0,SEEK_SET);
    file_to_num(fp,num);                     //将文件读出并转换成数组
     
    order_num(num);                          //对数组进行排序
 
    fseek(fp,0,SEEK_SET);
    order_to_file(fp,num);                   //将新数组写入文件

    fseek(fp,0,SEEK_SET);
    fgets(str,LEN,fp);                       //读出文件并打印出文件内容
    printf("the ordering num : %s\n",str);  

    return 0;
}
