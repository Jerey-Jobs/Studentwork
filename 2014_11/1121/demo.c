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
#define LEN 12

enum RETURN{SUCCESS};

int itoa(int num,char *str)
{
    int power;
    int flag = num;

    for(power = 1; flag >= 10; flag = flag / 10)
    {
        power = power * 10;
    }

    for( ;power > 0; power = power / 10)
    {
        *str = num / power + '0';
        num = num % 10;
        str++;
    }
    *str++ = ' ';
    *str = '\0';

}

int str2int(char *head,char *tail)
{
    int sum = 0;

    while(head < tail)
    {
        sum = sum * 10 + (*head - '0');

        head++;
    }
    sum = sum * 10 + (*head - '0');
    
    return sum;
}

int my_strtok(char *str,int *num)
{
    char *head = str;
    char *tail;

    while(*str != '\0')
    {
        if(*str == ' ' || *str == '\n')
        {
            tail = str - 1;

            *num = str2int(head,tail);

            num++;
            head = str + 1;
        }
        
        str++;
    }
}


int write_line(int fd,char *buf,int len)
{
    int tmp;

    if((tmp = write(fd,buf,strlen(buf))) == -1)
    {
        perror("write error");
        exit(1);
    }
    
    write(fd,"\n",1);

    return SUCCESS;
}

/*将fd文件中数据读出转成整形并存放在num数组中*/
int file2int(int fd,char *buff,int *num)
{
    
    if(read(fd,buff,MAX) == -1)
    {
        perror("read error");
    }
    
    my_strtok(buff,num);
   
}

int my_add(int *num1,int *num2,int *result)
{
    int i;

    for(i = 0; i < LEN; i++)
    {
        *(result + i) = *(num1 + i) + *(num2 + i);
    }
}

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
      
        strcat(line_buf,tmp_str);                //连接行缓冲与字符缓冲
        

        if((i + 1) % 4 == 0)
        {
             write_line(fd,line_buf,strlen(line_buf));

             memset(line_buf,0,strlen(line_buf));
        }

        num++;
    }

    write(fd,'\0',1);
}

int main(int argc,char *argv[])
{
    int i;

    char src1[MAX];
    char src2[MAX];
    char result_buf[MAX];

    int num1[LEN];
    int num2[LEN];
    int result[LEN];

    int fd_1;                         //文件描述符
    int fd_2;                         //文件描述符
    int fd_3;                         //文件描述符

    /*创建文件并打开*/
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

    file2int(fd_3,result_buf,result);
    printf("3.txt\n%s\nend\n",result_buf);
    

    return 0;
}
