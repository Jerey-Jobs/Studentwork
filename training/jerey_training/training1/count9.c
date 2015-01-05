/*************************************************
Copyright (C), 1988-1999, Lighting Tech.Co., Ltd.
File name:  count9.c
Author:  Jerey     Version: 0.1       Date: 2014/10/14
Description:   统计 1～n 有多少个9   
Function List: 
               1. int howmany9(int num)
               2. int whole_9(int n)
 **************************************************/

#include<stdio.h>

/*************************************************
Function:       int howmany9(int num)
Description:    统计一个数字中有几个9
Calls:          no
Called By:      int whole_9(int n)
Input:          num    被统计的数字
Return:         count  该数含9的个数     
*************************************************/
int howmany9(int num)
{
    int tmp;
    int count = 0;

    /*取出每一位数与9比较,若为9  count＋1 */
    while(num > 0)
    {
        tmp =  num % 10;         //eg: 123 % 10 = 3 ; 123 / 10 = 12
        num = num / 10;
        
        if(tmp == 9)
        {
            count++;
        }
    }

    return count;                //返回该数含9的个数   
}

/*************************************************
Function:       int whole_9(int n)
Description:    统计 1-n 有几个9
Calls:          int howmany9(int num)
Called By:      main
Input:          n      统计的最后一个数字
Return:         result  9的总数     
*************************************************/
int whole_9(int n)
{
    int i;
    int result = 0;

    /*统计1到n有多少个9*/
    for(i = 1; i <= n; i++)
    {
        result += howmany9(i);
    }

    return result;              //总数返回给main
}

int main()
{
    int num;                     

    printf("input the number:");
    scanf("%d",&num);
    
    printf("output : %d\n",whole_9(num));     //调用whole_9 函数 将其返回的9的总数输出
 
    return 0;
}
