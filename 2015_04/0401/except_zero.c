#include <stdio.h>
#include <stdlib.h>
    int n;

int func(int *a)
{
    int i;
    int j;
    for(i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            for(j = i; j < n; j++)
            {
                a[j] = a[j + 1];            
            } 
            n--;
            i--;      
        }       
    }   
}

int main()
{
    int a[100];
    int i;

    scanf("%d",&n);

    for(i = 0; i < n;i++)
    {
        scanf("%d",&a[i]);    
    }	
   
    func(a);
    
    printf("%d\n",n);
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);    
    }
    printf("\n");
    
	system("pause");
	return 0;
}
