//给出一个字节中被置为1的个数
#include<stdio.h>
int main()
{
    char c;
    int i, t, w=0; 
    printf("输入:");
    scanf("%c",&c);
    for(i = 0; i < 8; i++)
    {
        t=c&1;
        c=c>>1;
        if(t==1)
            w++;
    }
    printf("被置1的个数为：%d\n ",w);

return 0;
}
