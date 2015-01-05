#include<stdio.h>
int main()
{
	int find(int);
	int n, num;
	printf("输入n的值：");
	scanf("%d",&n);
	num = find(n);
	printf("留下的是第 %d 个\n",num);
	return 0;
}

int find(int n)
{
	int c[n];
	int *p = &c[0];
	int j;
	int i = 0, numb=0;
	int s = 0;
	for(j = 0; j < n; j++)
		c[j]=1;
	while(numb != (n-1))
	{
			if(*(p+i) == 1)
			{		
				s++;
				if(s%3 == 0)
				{
					*(p+i) = 0;
					numb++;
				}
			}	
			i++;

			if(i == n)
				i = 0;		
			
	}	
	
	for(j = 0; j < n; j++)
	{
		if(*(p+j)==1)
		return j+1;		
	}
}

