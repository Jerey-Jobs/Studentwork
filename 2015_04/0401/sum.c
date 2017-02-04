#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[100];
    int n;
    int sum = 0;
    scanf("%d",&n);
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];    
    }
    
    printf("%d %d",sum,sum/n);
    
	
	system("pause");
	return 0;
}
