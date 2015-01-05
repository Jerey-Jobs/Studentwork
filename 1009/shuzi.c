#include<stdio.h>
int main()
{
	char str[100];
	int i, j = 0;
	int max[100]={0};
	printf("输入字符串：");
	gets(str);
	for(i = 0; i < 100; i++)
	{
		if(('0' <= str[i])&&(str[i] <= '9'))
		{
			max[j]++;
		}
		else j++;
	}
	for(i = 0; i < 100; i++)
	{
		if(max[0]<max[i])
		{
			max[0]=max[i];
		}
	}
	printf("\n输出%d\n",max[0]);
	
	return 0;

