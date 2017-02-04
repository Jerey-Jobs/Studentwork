#include <stdio.h>

struct note
{
   int x;
   int y;
   int step;
};

int main()
{
    struct note que[2051];

    int a[50][50];
    int book[50][50];
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int head = 0;
    int tail = 0;
    int n;
    int startx,starty;
    int tx,ty;
    int tmpx,tmpy;
    int i,j;
    int flag = 0;

    scanf("%d",&n);
    scanf("%d%d%d%d",&startx,&starty,&tx,&ty);

    for(i = 0; i < n; i++)
    {
    	for(j = 0; j < n; j++)
    	{
    		scanf("%d",&a[i][j]);
    	}
    }

    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].step = 0;

    tail++;
    book[startx][starty] = 1;

    while(head < tail)
    {
    	for(i = 0; i < 4; i++)
    	{
    		tmpx = que[head].x + next[i][0];
    		tmpy = que[head].y + next[i][1];

    		if(tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= n)
    		{
    			continue;
    		}

    		if(a[tmpx][tmpy] == 0 && book[tmpx][tmpy] == 0)
    		{
    			book[tmpx][tmpy] = 1;
    			que[tail].x = tmpx;
    			que[tail].y = tmpy;
    			que[tail].step = que[head].step + 1;
    			tail++;
    		}

    		if(tmpx == tx && tmpy == ty)
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

