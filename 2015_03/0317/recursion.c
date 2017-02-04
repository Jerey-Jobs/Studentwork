#include <stdio.h>

int f(int *a,int end)
{
    if(end == -1)
    {
    	return 0;
    }

    int result = f(a,end - 1);

    return a[end] + result;
}



int main(int argc, char const *argv[])
{
	int a[5] = {4,5,6,3,5};

printf("%d\n", f(a,4));  

	return 0;
}

