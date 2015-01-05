//用递归的方法实现n的阶乘
#include<stdio.h>
int main()
{   
    int jc(int t);
    int n, b;
    printf("输入n的值：");
    scanf("%d",&n);
    b=jc(n);
    printf("n的阶乘为：%d",b);
    return 0;
}

int jc(int t)
{
    if(t > 1)
        return t*jc(t-1);

}
