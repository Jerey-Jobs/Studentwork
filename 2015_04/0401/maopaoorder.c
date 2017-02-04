#include <stdio.h>
#include <stdlib.h>

  int n;

int array(int a[])
{
    int i;
    int j;
    int tmp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;            
            }        
        }    
    }

}

int main()
{
    int a[200];
    int i;
  
    
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    array(a);
    
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
	
	system("pause");
	return 0;
}
