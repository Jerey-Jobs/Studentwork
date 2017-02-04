#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int n;
    int a[32];
    
    scanf("%d",&n);    
    
    for(i = 0; i < 32; i++)
    {
       a[i] = (n>>i) & 0x01;    
    }	
    
    for(i = 31; i >= 0; i--)
    {
       printf("%d",a[i]);    
    }    
    
	system("pause");
	return 0;
}
