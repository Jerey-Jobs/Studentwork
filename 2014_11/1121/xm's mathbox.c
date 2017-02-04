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

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define MAX 100
#define LEN 12                    //3*4魔方12个数据

enum RETURN{SUCCESS};

/*整形转字符串*/
int itoa(int num,char *str)
{
    int power;                    //权
    int flag = num;               //临时变量

    /*eg: flag = 123  =>  power = 100*/
    for(power = 1; flag >= 10; flag = flag / 10)
    {
        power = power * 10;
    }
    /*eg: 123 / 100 = 1 ; 123 % 100 = 23; 23 / 10 = 2*/
    for( ;power > 0; power = power / 10)
    {
        *str = num / power + '0';  // 1 + '0' = '1' 
        num = num % 10;
        str++;
    }
    *str++ = ' ';                  //在字符串结尾加个空格
    *str = '\0';
}

/*字符串转整形*/
int str2int(char *head,char *tail)
{
    int sum = 0;                   //结果

    /*eg: 123 = 12 * 10 + 3*/
    while(head <= tail)
    {
        sum = sum * 10 + (*head - '0');        //eg: 2 = '2' - '0'

        head++;
    } 
    
    return sum;                    //返回总和
}

/*将一个字符串解析成整形并存放在num数组中*/
int my_strtok(char *str,int *num)
{
    char *head = str;              //数字头指针
    char *tail;                    //数字结束指针

    /*遍历str 找个每个数字的头尾指针*/
    while(*str != '\0')
    {
        if(*str == ' ' || *str == '\n')    //遇到空格和回车表示一个数字结束
        {
            tail = str - 1;       

            *num = str2int(head,tail);     //调用str2int将head至tail之间的字符转换成整形

            num++;                         
            head = str + 1;                //下个数字开头即空格的下一个
        }
        
        str++;
    }
}

/*行写入函数 ，将buf缓冲区的字符串写入文件作为一行*/
int write_line(int fd,char *buf,int len)
{
    int tmp;
    
    /*若未写入成功 打印出错原因*/
    if((tmp = write(fd,buf,strlen(buf))) == -1)
    {
        perror("write error");
        exit(1);
    }
    
    write(fd,"\n",1);          //在行尾加换行符号

    return SUCCESS;            
}

/*将fd文件中数据读出转成整形并存放在num数组中*/
int file2int(int fd,char *buff,int *num)
{
    /*若读取失败打印读取错误信息*/
    if(read(fd,buff,MAX) == -1)
    {
        perror("read error");
    }
    
    my_strtok(buff,num);     //调用strtok将字符串解析成整形存num数组
}

/*求和函数 num1数组和num2数组元素挨个相加存放在result数组中*/
int my_add(int *num1,int *num2,int *result)
{
    int i;

    for(i = 0; i < LEN; i++)
    {
        *(result + i) = *(num1 + i) + *(num2 + i);
    }
}

/*数组转字符串函数，并每4个数写入进文件一行*/
int int2str(int *num,int fd)
{
    int i;
    char line_buf[MAX] = {0};                    //行缓冲
    char tmp_str[LEN];                           //数字缓存区
    char *p = line_buf;

    for(i = 0; i < LEN; i++)
    {
        memset(tmp_str,0,sizeof(tmp_str));       //数字缓存清空

        itoa(*num,tmp_str);                      //将num转换成字符串存在tmp—str中
       // printf("tmp:%s",tmp_str);

        strcat(line_buf,tmp_str);                //连接行缓冲与字符缓冲
        
       //这边有问题   printf("line buf : %s",line_buf);
        /*若行缓冲有4个数，行写入fd文件中*/
        if((i + 1) % 4 == 0)
        {
             write_line(fd,line_buf,strlen(line_buf));

             memset(line_buf,0,strlen(line_buf)); //写入完毕将行缓冲清空
        }

        num++;
    }

    write(fd,'\0',1);                              
}

int main(int argc,char *argv[])
{
    int i;

    char src1[MAX];                   //存放文件1内容
    char src2[MAX];                   //存放文件1内容
    char result_buf[MAX];             //存放文件1内容           

    int num1[LEN];                    //文件1数组
    int num2[LEN];                    //文件2数组
    int result[LEN];                  //结果数组

    int fd_1;                         //文件1描述符
    int fd_2;                         //文件2描述符
    int fd_3;                         //文件3描述符

    /*打开3个文件若不存在则创建：*/
    if((fd_1 = open("1.txt",O_CREAT | O_RDWR,0755)) == -1)
    {
        perror("open file 1 error");
    }

    if((fd_2 = open("2.txt",O_CREAT | O_RDWR,0755)) == -1)
    {
        perror("open file 2 error");
    }

    if((fd_3 = open("3.txt",O_CREAT | O_RDWR,0755)) == -1)
    {
        perror("open file 3 error");
    }

    file2int(fd_1,src1,num1);               //将fd—1文件中数据读出并转换成整形到数组num1中
    file2int(fd_2,src2,num2);               //将fd—2文件中数据读出并转换到整形数组num2中
    
    printf("1.txt\n%s\nend\n",src1);        //打印出文件1内容
    printf("2.txt\n%s\nend\n",src2);        //打印出文件2内容

    my_add(num1,num2,result);               //num1数组与num2相加存放到result数组中

    int2str(result,fd_3);                   //将result数组内容每行4个数据存放到文件3中

    lseek(fd_3,0,SEEK_SET);                 

    if(read(fd_3,result_buf,MAX) == -1)     //将fd_3文件中数据读出
    {
        perror("read fd_3 error");
    }       

    printf("3.txt\n%s\nend\n",result_buf);  //打印出文件3内容
    

    return 0;
}
