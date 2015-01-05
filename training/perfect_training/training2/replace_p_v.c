/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：   training2_4.c
Author：Jerey_Jobs    Version:0.1    Date: 2014/10/21
Description：输入一个整数a,再输入两个整数p(p<32),v(0|1),将该整数a的p位
             设置为v,输出修改后的该整数的二进制表示.
Funcion List: 
             1.int dec2bin(int num,int *p)
             2.int replace(int *num_bin,int *out_bin,int p, int v)
*****************************************************/

#include <stdio.h>

/*************************************************
Function:       int dec2bin(int num,int *p)
Description:    将十进制形参num转换成二进制存入p所指数组
Calls:          no
Called By:      main
Input:          int num   十进制n
                int *p    目标数组
Return:         no
*************************************************/ 

int dec2bin(int num,int *p)
{
    int i;
    
    /*除2取余将十进制转换成2进制*/
    for(i = 0; i < 32; i++)
    {
        *p = num % 2;
        num = num / 2;
        p++;
    }
}


/*************************************************
Function:       int replace(int *num_bin,int *out_bin,int p, int v)
Description:    将num_bin中第p个数改成v并复制进out_bin数组
Calls:          no
Called By:      main
Input:          int *num_bin   原二进制数组
                int *out_bin   存放结果数组
                int p          需要改的位
                int v          改变的值
Return:         no
*************************************************/ 
int replace(int *num_bin,int *out_bin,int p, int v)
{
    int i;

    /*将num_bin中第p个数改成v并复制进out_bin数组*/
    for(i = 0; i < 32; i++)        
    {
        *out_bin = *num_bin;

        if(i == p - 1)            //第p个数 即p－1位   
        {
            *out_bin = v;
        }

        *num_bin++;
        *out_bin++;
    }
}


int main()
{
    int i;
    int num;                       //输入
    int p;                         //需要改变的位
    int v;                         //改变目标
    int num_bin[32];               //存放输入整数的二进制
    int out_bin[32];               //存放结果二进制

    printf("input the number :");  
    scanf("%d",&num);

    printf("input p :");
    scanf("%d",&p);

    printf("input v :");
    scanf("%d",&v);

    dec2bin(num,num_bin);           //调用dec2bin将num转成2进制并存放进数组
    
    replace(num_bin,out_bin,p,v);   //调用replace函数将num—bin里p位替换成v

    printf("原数的二进制为：");
    for(i = 31; i >= 0; i--)        //二进制低位在右 因此逆序输出
    {
        printf("%d",num_bin[i]);
    }
    printf("\n");

    printf("修改后的数的二进制为：");
    for(i = 31; i >= 0; i--)        //逆序输出同上
    {
        printf("%d",out_bin[i]);
    }
    printf("\n");

    return 0;
}
