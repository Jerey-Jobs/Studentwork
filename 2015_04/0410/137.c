#include <stdio.h> 

void main()
{ 
	int a[10],n,max; 
	int b[4]={1,3,7,8}; 
    int flag[20]={0}; 
    int i,j; 

    max = 0 ;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{ 
		scanf("%d",a+i); 
		if(a[i]>max) 
		max = a[i] ; 
	}

	for(i=2;i<=max;i++)
	{  
		for(j=0;j<4 && b[j]<i;j++)
		{    
		 	if(flag[i-b[j]]==0)
		 	{     
		 		flag[i] = 1; 
		 		break;   
		    }
		}
    }

 	for(i=0;i<n;i++)
 	   printf("%d\n",flag[a[i]]); 
}