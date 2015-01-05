/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：    reserve_p1p2.c
Author：Jerey_Jobs    Version:0.1    Date:2014/10/21
Description:    输入一个整数a,再输入两个整数p1,p2(p1,p2<32),将该整数的二进制
                表示方法中从右端开始的p1到p2位取反后输出
Funcion List: 
             1.int dec2bin(int num,int *bin)
             2.int reverse_p1p2(int src,int p1,int p2)
*****************************************************/

#include <stdio.h>

/*************************************************
Function:       int dec2bin(int num,int *bin)
Description:    十进制转二进制，并将2进制存在bin数组中
Calls:          no
Called By:      main
Input:          int num      代转换十进制
                int *bin     存放二进制数组
Return:         no
*************************************************/ 
int dec2bin(int num,int *bin)
{
    int i;

    /*除2取余的方法将十进制转换成二进制*/
    for(i = 0; i < 32; i++)
    {
        *(bin + i) = num % 2;
        num = num / 2;
    }
}


/*************************************************
Function:       int reverse_p1p2(int src,int p1,int p2)
Description:    将src右端p1至p2位取反
Calls:          no
Called By:      main
Input:          int src  待操作整数
                int p1   右端起始位
                int p2   结束位
Return:         no
*************************************************/ 
int reverse_p1p2(int src,int p1,int p2)
{
    int i;
    int sum = 0;
    int post = 1;          //2进制的权
    
    /*得到一个p1至p2位均为1 其他位为0 的数 sum*/
    for(i = 0; i < 32; i++)
    {
        if(i >= (p1 - 1) && i < p2)
        {
            sum += post;
        }

        post = 2 * post;
    }

    src = src ^ sum;     //eg: 10101 ^ 00110 = 10011

    return src;         
}

int main()
{
    int i;
    int num;             //输入数
    int p1;              //右起始位
    int p2;              //结束位
    int bin[32];         //存放二进制

    printf("please input a number:");
    scanf("%d",&num);

    printf("please input p1 and p2 :");
    scanf("%d %d",&p1,&p2);

    num = reverse_p1p2(num,p1,p2);    //将num 的p1-p2位取反

    dec2bin(num,bin);                 //将num 转换成二进制

    printf("输出的二进制形式为:");
    for(i = 31; i >= 0; i--)          //2进制低位在右 逆向输出
    {
        printf("%d",bin[i]);
    }

    printf("\n转换后的整数为: %d\n",num);

    return 0;
}
