//第p位用ｖ替代，输出二进制
#include<stdio.h>
int main()
{
    int a, i;
    int m[32];
    int p, v;
    printf("输入一个数a:");
    scanf("%d",&a);
    printf("输入p的值和V的值：");
    scanf("%d %d",&p,&v);
    for(i = 0; i < 32; i++)
    {
        m[i]=a%2;
        a=a/2;
    }
    printf("原数的二进制：");
    for(i = 31; i >= 0; i--)
        printf("%d",m[i]);
    printf("\n");
    m[p-1]=v;
    printf("改变后的数的二进制：");

    for(i = 31; i >= 0; i--)
        printf("%d",m[i]);
    printf("\n");

    
    return 0;
}
