#include <stdio.h>

int main()
{
	int n;
	int i;

    scanf("%d",&n);
    
    if(n == 1)
    {
    	    printf("\\n");
            return 1;
    }
  
    for(i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            printf("\\n");
            return 1;
        }
    }

    printf("\\t");
    return 0;
}

