/*************************************************
Copyright (C), 2014－2015, Lighting Tech.Co., Ltd.
File name:     find_str_num.c
Author:  Jerey     Version: 0.1       Date: 2014/10/15
Description:    计算字符串中子串出现的次数    
Function List: 
              1.int my_strlen(char *point)
              2.int my_strcmp(char *dest, char *ptr)
              3.int find_ptr_num(char *str, char *ptr)
*************************************************/
#include<stdio.h>

/*************************************************
Function:       int my_strlen(char *point)
Description:    测量该字符串的长度
Calls:          no
Called By:      int my_strcmp(char *dest, char *ptr)
Input:          point   待测字符串
Return:         len  字符串长度
*************************************************/
int my_strlen(char *point)
{
    int len = 0;

    while(*point != '\0')                  //遍历字符串测量长度
    {
        len++;
        point++;
    }

    return len;                            //返回长度
}


/*************************************************
Function:       int my_strcmp(char *dest, char *ptr)
Description:    比较dest字符处后面的与ptr等长的字符串是否与ptr相同；
                若相同，返回1
                若不同，返回0
Calls:          int my_strlen(char *point)
Called By:      int my_strcmp(char *dest, char *ptr)
Input:          dest  被比较字符串
                ptr   原字符串
Return:         0  与ptr不同
                1  与ptr相同
*************************************************/
int my_strcmp(char *dest, char *ptr)
{

    /*比较待比较字符串与子字符串长度,若子串比待比较的长，则返回0*/
    if(my_strlen(dest) < my_strlen(ptr))         
    {
        return 0;                           
    }
    
    /*比较dest后面与ptr等长的字符串是否与ptr相等 */
    int i;
    int len;
    len = my_strlen(ptr);                      //调用my_strlen 测ptr长度
    for(i = 0; i < len; i++)
    {
        if(*(dest + i) != *(ptr + i))          //若不等,则结束并返回0         
        {
            return 0;                  
        }
    }
    
    return 1;                                  //若相同,则返回1
}


/*************************************************
Function:       int find_ptr_num(char *str, char *ptr)
Description:    计算str中ptr子串出现的次数count
Calls:          int  my_strcmp(char *str,char *ptr);
Called By:      main
Input:          str     主字符串
                ptr     子字符串
Return:         count   str中ptr子串出现的次数
*************************************************/
int find_ptr_num(char *str, char *ptr)
{
    int count = 0;                    //存放出现次数 
    
    while(*str != '\0')
    {
        count += my_strcmp(str,ptr);  //调用my_strcmp(str,ptr)若相同count+1 不同 +0    
        str++;
    }

    return count;                     //返回出现次数给main
}


int main()
{
    char str[100];                    //主字符串
    char ptr[100];                    //子字符串
    int count;                        //存放次数

    printf("input str :");
    scanf("%s",str);
    printf("input ptr :");
    scanf("%s",ptr);
   
    count = find_ptr_num(str,ptr);           //调用find_ptr_num 函数找出子串出现次数

    printf("output number is: %d\n",count);

    return 0;
}

