/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   training1_4.c
Author：Jerey_Jobs    Version:0.1    Date:2014/10/18 
Description：  求100以内的素数,全部打印出来
Funcion List: 
             1.int judge(int n)
             2.int find_prime(int n)
*****************************************************/

#include <stdio.h>
/*************************************************
Function:       int judge(int n)
Description:    判断一个数是否是素数，若是 返回1 不是 返回0
Calls:          no
Called By:      int find_prime(int n)
Input:          int n   待判断的数
Return:         0       不是素数
                1       是素数
*************************************************/ 
int judge(int n)
{
    int i;
    
    /*令该数除以2～n－1 若存在能整除的 则不是素数 */
    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return 0; 
        }
    }

    return 1;
}

/*************************************************
Function:       int find_prime(int n)
Description:    挨个判断n之内哪些是素数 若是素数则输出
Calls:          int judge(int n)
Called By:      main
Input:          int n  判断范围
Return:         no
*************************************************/ 
int find_prime(int n)
{

    int i;

    /*挨个判断每个数是否是素数，若是则输出*/
    for(i = 2; i <= n; i++)             //素数肯定从2开始(常识))           
    {
        if(judge(i) == 1)               //调用judge 函数判断该数是否是素数
        {
            printf("%d ",i);
        }
    } 
    printf("\n");
}

int main()
{
    printf("prime < 100 is :");
    find_prime(100);                    //调用find_prime 函数将100内的素数都输出

    return 0;
}
