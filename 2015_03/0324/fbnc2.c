#include <stdio.h>

int main()
{
    int ans[100000];

    ans[1]=ans[2]=1;
    
    int n;
    int i;

    scanf("%d",&n);
    for(i=3;i<=n;i++)
        ans[i]=(ans[i-1]+ans[i-2])%10007;
    printf("%d\n",ans[n]);
    return 0;
}