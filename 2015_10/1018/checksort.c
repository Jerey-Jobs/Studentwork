#include <stdio.h>

int checksort(int a[],int n)
{
	int i;
	int up = 0;
	int down = 0;
	for(i = 1; i < n; i++)
	{
		if(a[i] > a[i - 1]) up = 1;
		else if(a[i] < a[i - 1]) down = 1;
		if(up && down) return -1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int a[5] = {1,6,3,4,5};

	printf("%d\n", checksort(a,5));
	return 0;
}

