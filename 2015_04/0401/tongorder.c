#include <stdio.h>
#include <stdlib.h>

int a[10000] = {0};

int main()
{
    int i;
    int j;
    int n;
    int flag;
    
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&flag);
        a[flag]++;
    }
    
    for(i = 0; i < 10000; i++)
    {
        for(j = 1; j <= a[i]; j++)
        {
            printf("%d\n",i);        
        }
    }

	system("pause");
	return 0;
}
