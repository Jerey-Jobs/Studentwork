#include <stdio.h>

int Sum(int* a, int n)
{
    int curSum = 0;
    int maxSum = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        if (curSum + a[i] < 0)
            curSum = 0;
        else
    	{
    		curSum= curSum + a[i];
    	    if(curSum > maxSum)
    		{
    			maxSum = curSum;
    		}	
    	}   
    }
    return maxSum;
}

int maxsub(int *a,int n)
{
    int i;
    int temp = 0,maxn = -999,k=1;
    int start,end;

    for(i = 0 ; i < n ;i++)
    {
         temp += a[i];

        if(temp > maxn)
        {
            maxn = temp;start = k ;end = i;
        }

        if(temp < 0)
        {
            temp = 0;k = i+1;
        }
    }
    return maxn;
}

int main()
{
	int i;
    int n = 4;
    int a[100] = {5,6,-4,1};
    // scanf("%d",&n);
    // for(i = 0; i < n; i++)
    // {
    // 	scanf("%d",&a[i]);
    // }
    int result;
	result = Sum(a,n);
    printf("%d\n",result);
    getchar();
    getchar();


	return 0;
}
