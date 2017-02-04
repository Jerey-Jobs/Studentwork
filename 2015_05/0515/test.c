#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int main() 
{
    int a;
    int num[32]={0};
    while(~scanf("%d",&a) != EOF) 
	{
        num[a]++;
    }
    for(a=0;a<32;a++)
    {
    	if(num[a]>1)
    		printf("%d show %d times.\n",a,num[a]);
    }
    system("pause");
	return 0;
}
