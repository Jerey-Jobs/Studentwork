/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：      perfect_num.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/18
Description：   一个数如果恰好等于它的因子之和,这个数被成为”完数”
                例如:6=1+2+3.找出1000以内的完数
Funcion List:   
              1.int find_num(int n)
*****************************************************/

#include <stdio.h>

/*************************************************
Function:       int find_num(int n)
Description:    找出1000内的完数 并输出
Calls:          no
Called By:      main
Input:          int n  完数的范围
Return:         no
*************************************************/ 
int find_num(int n)
{
    int i;                   
    int j;
    int sum;                           //约数和

   /*用整除的方法寻找该数约数并求和*/
    for(i = 2; i < 1000; i++)          //2～n进行寻找
    {
        sum = 0;
        for(j = 1; j < i; j++)         //对每个数求约数并求和
        {
            if(i % j == 0)              
            {
                sum += j;
            }
        }
        
        /*如果这个数的约数和等于这个数 则输出该数*/
        if(sum == i)
        {
            printf("%d  ",i);
        }

    }

    printf("\n");
}


int main()
{
    printf("the number is: ");
    find_num(1000);                     //调用find_num函数找出1000内完数并输出
    return 0;
}
