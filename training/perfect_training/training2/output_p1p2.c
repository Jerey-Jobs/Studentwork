/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：  training2_2.c
Author：Jerey_Jobs    Version:0.1    Date:  2014/10/19
Description：输入一个整数a,再输入两个整数p1,p2(p1,p2<32),输出该整数的
             二进制表示方法中从右端开始的p1到p2位.
Funcion List:  int outputp1_p2(int n,int p1,int p2)
*****************************************************/

#include <stdio.h>

/*************************************************
Function:       int outputp1_p2(int n,int p1,int p2)
Description:    将n的二进制表示中p1到p2的位存入数组 并输出
Calls:          no
Called By:      main
Input:          int n       被表示整数
                int p1      右端开始位
                int p1      结束位
Return:         no
*************************************************/ 
int outputp1_p2(int n,int p1,int p2)
{
    int len;                    //要输出的长度
    int i;                
    int src[32] = { 0 };        //存放结果       

    n = n >> (p1-1);            //右移n 使p1所在成为右边第一位
    len = p2 - p1;

    /*与1相与取出最后一位存入src 直至取出len位*/
    for(i = 0; i < len; i++)    
    {
        src[i] = n & 1;
        n = n >> 1;      
    }

    printf("output :");
    for(i = len; i >= 0; i--)    //因为p1放在第一个 因此要逆序输出
    {
        printf("%d",src[i]);
    }
    printf("\n");

}

int main()
{
    int num;                        
    int p1;                          //开始位
    int p2;                          //结束位

    printf("please input number:");
    scanf("%d",&num);

    printf("input p1 and p2 : ");
    scanf("%d %d",&p1,&p2);

    outputp1_p2(num,p1,p2);          //调用outputp1_p2函数 输出num中p1到p2位


    return 0;
}
