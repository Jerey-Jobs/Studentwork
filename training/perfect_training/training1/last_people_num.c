/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   training1_2.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/18
Description： 有n个人围成一圈,顺序排号,从第一个开始报数(从1到3报数),凡报到3的人
              退出圈子,求最后最后留下的是原来第几号的那位.
Funcion List: 
              1. int find(int num)
*****************************************************/

#include <stdio.h>

/*************************************************
Function:       int find(char num)
Description:    找出最后留下的是第几人
Calls:          no
Called By:      main
Input:          int num  人数
Return:         i+1      剩下的人的位置
*************************************************/ 
int find(int  num)
{
    int people[num];                   //将num个人存入数组
    int i;
    int j = 0;
    int leave_people = 0;              //离开人数
    int number = 0;                    //报数

    /*将数组初始化全部置1*/
    for(i = 0; i < num; i++)
    {
        people[i] = 1;
    }

    /*不断t出人，直到人数只剩一个为止*/
    while(leave_people != num - 1)
    {
        if(people[j] == 1)              //若该元素为1 报数加1
        {
            number++;                   
       
    /*若该人报数能整除3 则该元素置0 并且离开人数＋1*/
            if(number % 3 == 0)
            {
                people[j] = 0;
                leave_people++;
            }
        }

        j++;

    /*当报数进行到最后一人时，j置0 从头开始继续报*/
        if(j == num)
        {
            j = 0;
        }
    }
    
    /*找出数组中唯一没被置0的元素 返回该元素位置*/
    for(i = 0; i < num; i++)
    {
        if(people[i] == 1)
        {
            return i + 1;
        }
    }
}


int main()
{
    int num;                                  //人数

    printf("input people number :");
    scanf("%d",&num);
    
    printf("留下的是第 %d 个\n",find(num));   //调用find 函数，找出最后的人的位置


    return 0;
}
