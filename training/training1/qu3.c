#include<stdio.h>
int main()
{
    int n, i, j=0;
    int num = 0;
    int tui = 0;
    printf("shuru n:");
    scanf("%d",&n);
    int a[n]; 
    for(i = 0; i < n; i++)
        a[i] = 1;
        
    while( tui != (n-1))
    {   
        if(a[j] == 1)
        {
            num++;
             if(num%3 == 0)
             {
                 a[j] = 0;
                 tui++; 
             }
        }
        j++;
        if(j==n)
             j=0;
        
    }
    for(i = 0; i < n; i++)
        if(a[i]==1)
       printf("the number is %d\n",i+1);

return 0;
}
