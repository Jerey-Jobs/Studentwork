#include<stdio.h>
int main()
{
    int a, b;
	printf("请输入a和b：");
    scanf("%d %d",&a,&b);
    printf("add=%d\n",add(a,b));
    printf("sub=%d\n",sub(a,b));
    printf("mul=%d\n",mul(a,b));
return 0;
}
