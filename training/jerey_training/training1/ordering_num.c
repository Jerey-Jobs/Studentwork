/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：  ordering_num.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/18
Description：输入5个数(含负数、小数)将它们按由小到大的顺序排列起来
Funcion List:    
             1.int ordering(float a[5])
*****************************************************/

#include <stdio.h>
/*************************************************
Function:       int ordering(float a[5])
Description:    冒泡法排序，由小到大排序
Calls:          no
Called By:      main
Input:          a[5]  待排序的5个数
Return:         no
*************************************************/ 
int ordering(float a[5])
{
    int i;
    int j;
    float tmp;
    
    /*冒泡排序法 从小到大排序*/
    for(i = 0; i < 4; i++)              //进行4次循环，实现4趟比较
    {
        for(j = 0; j < 4 - i; j++)      //每一趟中进行4－i次比较。。。
        {
            if(a[j] > a[j + 1])         //每次比较 小的数放前面
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

}

int main()
{
    int i;                            
    float num[5];                      //存放5个数
    
    printf("请输入5个数:");            //输入数组
    for(i = 0; i < 5; i++)
    {
        scanf("%f",&num[i]);
    }

    ordering(num);                     //调用ordering 函数将数组排序 

    printf("由小到大为:");             //输出数组
    for(i = 0; i < 5; i++)
    {
        printf("%g ",num[i]);
    }
    printf("\n");

    return 0;
}
