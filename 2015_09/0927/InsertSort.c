#include <stdio.h>
void print(int a[],int n,int i)
{
	int j;
	printf("%d:",i);
	for(j = 0; j < n; j++)
	{
		printf("%d ",a[j]);
	}
	printf("\n");
}


// void InsertSort(int a[],int n)
// {
// 	int i;
// 	int j;
// 	for(i = 1; i < n; i++)
// 	{	
// 		if(a[i] < a[i-1])
// 		{
// 			int tmp = a[i];
// 			for(j = i - 1;j >= 0 && a[j] > tmp; j--)
// 			{
// 				a[j + 1] = a[j];
// 			}
// 			a[j + 1] = tmp;;
// 		}
// 		print(a,n,i);
// 	}
// }


void InsertSort(int a[],int n)
{
	int i;
	int j;
	int key;
	for(i = 1; i < n; i++)
	{
		if(a[i] < a[i - 1])
		{
			key = a[i];
			for(j = i; j > 0 && a[j - 1] > key; j--)
			{
				a[j] = a[j - 1];
			}
			a[j] = key;
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[8] = {4,54,2,65,34,75,23,12};

	InsertSort(a,8);
	int i;
	for(i = 0; i < 8; i++)
	{
		printf("%d | ", a[i]);
	}
	printf(" \n");

	return 0;
}


