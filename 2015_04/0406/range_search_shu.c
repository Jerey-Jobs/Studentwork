#include "stdio.h"

int book[10];
int a[10][10];
int n;
int sum = 0;

int main(int argc, char const *argv[])
{
	int i;
	int j;
	int left,right;
	int que[1000];
	int head = 1;
	int tail = 1;

	int current_flag;


	scanf("%d",&n);

    for(i = 1; i <= n; i++)
    {
    	scanf("%d%d",&left,&right);
    	a[left][right] = 1;
    	a[right][left] = 1;
    }

    que[tail] = 1;
    tail++;
    book[1] = 1;

    while(head < tail)
    {
    	current_flag = que[head];
    	for(i = 1; i <= n; i++)
    	{
  			if(book[i] == 0 && a[current_flag][i] == 1)
  			{
  				que[tail++] = i;
  				book[i] = 1;
  			}

  			if(tail > n)
  			{
  				break;
  			}
    	}
    	head++;
    }


    for(i = 1; i <= n; i++)
    {
    	printf("%d ",que[i]);
    }
    getchar(); 
    getchar(); 
    return 0;
}


