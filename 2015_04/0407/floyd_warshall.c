#include <stdio.h>

 int main(int argc, char const *argv[])
{
	int a[50][50];
	int i;
	int j;
    int k;
	int n;
	int line_num;
    int length;
	int x,y;
	int start,end;

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
    	scanf("%d%d%d",&x,&y,&length);
    	a[x][y] = length;
    }

    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(a[i][j] > (a[i][k] + a[k][j]))
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    printf("%d",a[start][end]);

    getchar();
    getchar();



	return 0;
}


