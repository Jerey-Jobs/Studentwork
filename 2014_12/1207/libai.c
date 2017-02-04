/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
int sum=0;
int f(int a,int b,int c)
{
    if(a>0)
        f(a-1,b,c*2);
    if(b>0)
        f(a,b-1,c-1);
    if(a==0&&b==0&&c==1)
        sum=sum+1;
        return sum;
}
int main()
{

        f(5,9,2);
            printf("%d",sum);
}
