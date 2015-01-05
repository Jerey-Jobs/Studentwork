#include<stdio.h>
int main()
{
    int a, i, n;
    int m, s=0;
    int p1, p2;
    int r[16]={0};
    printf("输入一个数a：");
    scanf("%d",&a);
    printf("输入p1和p2:");
    scanf("%d %d",&p1,&p2);
    m=1;
    for(i = 0; i < 16; i++)
    {   
        
        if((i>=(p1-1))&&(i<p2))
            s=s+m;
        m=2*m;
    }
    n=a^s;
    printf("输出整数:");
    printf("%d\n",n);
    for(i = 0; i < 16; i++)
        {
            r[i] = n%2;
            n=n/2;
        }
    printf("输出二进制形式：");
    for(i = 15; i >= 0; i--)
        printf("%d",r[i]);
    printf("\n");
return 0;
}
