#include <stdio.h>

int a[50][50];
int book[50][50];
int n;
int px;
int py;
int min = 999;

void dfs(int x,int y,int step)
{
    int i;
    if(x == px && y == py)
    {
        if(step < min)
        {
            min = step;
        } 	
    }
    
    int key[4][2] = {
    	1,0,
        0,1,
        -1,0,
        0,-1
    };
    
    int tmpx,tmpy;
    for(i = 0; i < 4; i++)
    {
    	tmpx = x + key[i][0];
    	tmpy = y + key[i][1];
        if(tmpx >= 0 && tmpy >= 0 && tmpx < n && tmpy < n)
        {
    	    if(book[tmpx][tmpy] == 0 && a[tmpx][tmpy] == 0)
        	{	
                book[tmpx][tmpy] = 1;
                dfs(tmpx,tmpy,step + 1);
                book[tmpx][tmpy] = 0;
            }
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int i;
    int j;

    scanf("%d",&n);
    scanf("%d%d",&px,&py);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
        	scanf("%d",&a[i][j]);
        }
    }
	
    dfs(0,0,0);

    printf("%d\n",min);
    getchar();
    getchar();
    
	return 0;
}

