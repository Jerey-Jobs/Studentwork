/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name： training2_5.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/21
Description：输入一个32位的整数a,使用按位异或^运算,生成一个新的32位整数b,
             使得该整数b的每一位等于原整数a中该位左右两边两个bit位的异或结果
Funcion List: 
             1.int dec2bin(int n,int *p)
             2.int make_new(int *src,int *p)
*****************************************************/

#include <stdio.h>

/*************************************************
Function:       int dec2bin(int n,int *p)
Description:    将十进制整数n转换成2进制 保存在p所指数组里 
Calls:          no
Called By:      main
Input:          int n    待转换整数
                int *P   存放数组
Return:         no
*******************a******************************/ 
int dec2bin(int n,int *p)
{
    int i;

    /*除2取余 将十进制转换成2进制 */
    for(i = 0; i < 32; i++)
    {
        *p = n % 2;
        n = n / 2;
        p++;
    }
}

/*************************************************
Function:       int make_new(int *src,int *p)
Description:    使用异或运算生成一个新的32位数组
Calls:          no
Called By:      main
Input:          int *src  源数组指针
                int *p    声成的数组指针
Return:         no
*************************************************/ 
int make_new(int *src,int *p)
{
    int i;

    /*对原数组中每位左右两边两位异或并存入p所指数组中*/
    for(i = 0; i < 32; i++)
    {
        if(i == 0)                   //对于第0位 让0与第一位与非
        {
            *p = 0 ^ *(src + 1);
        }

        if(i == 31)                  //对于最后一位  让0与倒数第二位与非
        {
            *p = 0 ^ *(src - 1);      
            break;                   //最后一位赋值后不能继续执行要break跳出
        }

        *p = *(src - 1) ^ *(src + 1);

        p++;
        src++;

    }
}

int main()
{
    int i;
    int num;                          //输入的整数
    int src[32];                      //保存输入整数的二进制
    int new_bin[32];                  //保存结果

    printf("please input num :");
    scanf("%d",&num);

    dec2bin(num,src);                 //调用dec2bin 将num转换成二进制
    
    make_new(src,new_bin);            //调用make_new将输入的二进制按要求与或成新的数组

    printf("输入数字的二进制表示为:");
    for(i = 31; i >= 0; i--)          //二进制是低位在右,因此逆序输出
    {
        printf("%d",src[i]);
    }
    printf("\n");

    printf("新数的二进制表示为:");
    for(i = 31; i >= 0; i--)          //逆序输出
    {
        printf("%d",new_bin[i]);
    }
    printf("\n");

    return 0;
}
