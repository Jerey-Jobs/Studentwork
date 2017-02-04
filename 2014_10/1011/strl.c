#include<stdio.h>
int main()
{
	char a[1000];
//	char c;
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i]=-1-i;
	}
	printf("strlen (a) = %d\n",strlen(a));
	
//	for (i = 0; i < 1000; i++)
//		printf("%c ",a[i]);
	
	printf("%c ",-128);
return 0;
}
