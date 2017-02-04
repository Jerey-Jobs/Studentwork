#include <stdio.h>
#include <stdlib.h>

void cimi(int n)
{
    int num;
    int i,j,k;
    int a[32];//数组定义为局部变量 
    num=0;
    i=0;
    while(n)
    {
        j=n%2;
        if(j==1)
            a[num++]=i;//存储第几次是1 
        i++;
        n/=2;
    }
    for(i=num-1;i>=0;i--)
    {
        if(a[i]==0)
            printf("2(0)");
        else if(a[i]==1)
            printf("2");
        else if(a[i]==2)
            printf("2(2)");
        else if(a[i]>2)
        {
            printf("2(");
            cimi(a[i]);
            printf(")");
        }
        if(i!=0)
            printf("+");//如果不是最后一个就得输出 +  
    }
}

int main()
{
    int n;
    scanf("%d",&n);
        cimi(n);
     //   printf("\n");
	
	system("pause");
	return 0;
}
