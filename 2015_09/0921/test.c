#include <stdio.h>

void FastSort(int a[],int low,int high)
{
	if(low >= high)	return;

	int i = low;
	int j = high;
	int key = a[low];

	while(i < j)
	{
		while(i < j && a[j] >= key) j--;
		a[i] = a[j];
		while(i < j && a[i] <= key) i++;
		a[j] = a[i];
		a[i] = key;
	}
	FastSort(a,low,i - 1);
	FastSort(a,i + 1,high);
}

int main()
{
	int  a[10] = {2,1,5,6,3,6,2,12,7,9};

	FastSort(a,0,9);

	int i;
	for(i = 0; i < 10; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

}