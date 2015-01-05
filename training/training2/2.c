//输出从右端凯撒的P1到P2位。
#include<stdio.h>
int main()
{
    int a, i, n;  // a是数字，n是取出多岁位。。
    int p1, p2;
    int s[16];
    printf("输入一个数：");
    scanf("%d",&a);
    printf("输入p1和p2：");
    scanf("%d %d",&p1,&p2);
    a=a>>(p1-1);
    n=p2-p1;
    for(i = 0; i < n; i++)
    {
        s[i]=a&1;
        a=a>>1;
    }
    printf("输出：");
    for(i = n; i >= 0; i--)
        printf("%d",s[i]);
    printf("\n");

return 0;
}
