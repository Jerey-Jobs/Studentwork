#include <stdio.h>

struct node
{
	int num;
	int step;
};

 int main(int argc, char const *argv[])
{
	struct node que[2051];
	int a[50][50];
	int book[50];
	int head = 1;
	int tail = 1;
	int i;
	int j;
	int n;
	int line_num;
	int x,y;
	int start,end;
	int flag = 0;

    scanf("%d%d%d%d",&n,&line_num,&start,&end);

    for(i = 1; i <= n; i++)
    {
    	for (j = 1; j <= n; j++)
    	{
    		/* code */
    		a[i][j] = 999;
         
     	}
    }

    for(i = 1; i <= line_num; i++)
    {
    	scanf("%d%d",&x,&y);
    	a[x][y] = 1;
    	a[y][x] = 1;
    }

    que[tail].num = start;
    que[tail].step = 0;
    tail++;
    book[start] = 1;

    int cur;
    while(head < tail)
    {
        cur = que[head].num;
        for(i = 1; i <= n; i++)
        {
        	if(a[cur][i] == 1 && book[i] == 0)
        	{
        		que[tail].num = i;
        		que[tail].step = que[head].step + 1;
        		tail++;
        		book[i] = 1;
        	}

        	if(que[tail].num == end)
        	{
        		flag = 1;
        		break;
        	}
        }

        if(flag == 1)
        {
        	break;
        }
        head++;
    }

    printf("%d\n",que[tail - 1].step);

    getchar();
    getchar();



	return 0;
}


