/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int compare(char *src,char *p,int len)
{
    char *tmp ;
    
    while(*p != '\0')
    {
        if(*src == *p)
        {
            len++;
            p++;
            src++;
        }
        else 
            return len;
    }
}

char *find_max(char *src,char *p)
{
    int len = 0;
    int max = 0;
    char *start;


    while(*src != 0)
    {
        if(max < compare(src,p,len))
        {
            max = compare(src,p,len);
            start = src;
        }

        src++;
    }

    return start;

}

int main()
{
    char str_1[100];
    char str_2[100];
    

    printf("input the string1:");
    scanf("%s",str_1);

    printf("input the string2:");
    scanf("%s",str_2);
    
    printf("output is :%s",find_max(str_1,str_2));

    return 0;
}
