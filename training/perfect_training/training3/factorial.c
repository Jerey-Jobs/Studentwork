/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   training3_1.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/22
Description：利用递归方法实现一个函数,该函数能够实现n的阶乘
             即 n! = n*(n-1)*…*3*2*1;
Funcion List: 
             1.int factorial(int n)
*****************************************************/

#include <stdio.h>

/*************************************************
Function:       int factorial(int n)
Description:    用递归方法求一个数的阶层
Calls:          no
Called By:      main
Input:          int n  被求数
Return:         n * fanctorial(n - 1)  递归调用
*************************************************/ 
int factorial(int n)
{
    if(n == 1 || n == 0)              //0 和1特例 阶乘为1
    {
        return 1;
    }

    if(n > 1)
    {
        return n * factorial(n - 1);  //继续掉用factorial得到n*n-1*...*2*1
    }
}

int main()
{
    int num;              //输入数
    int result;           //结果

    printf("please input the number: ");
    scanf("%d",&num);

    result = factorial(num);          //调用factorial 求出num的阶乘

    printf("the factorial is : %d\n",result);

    return 0;
}
