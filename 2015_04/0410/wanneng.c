#include <stdio.h>

int a[5];
int book[5];

int dfs(int n)
{
	int i;
	if(n == 5)
	{
        for (i = 0; i < 5; i++)
        {
        	/* code */
        	printf("%d",a[i]);
        }
        printf("\n");
        return 0;
	}

	a[n] = 0;
	book[n] = 1;
	dfs(n + 1);
	book[n] = 0;

	a[n] = 1;
	book[n] = 1;
	dfs(n + 1);
	book[n] = 0;

}


int main(int argc, char const *argv[])
{
	dfs(0);

	getchar();
	getchar();
    	
	return 0;
}



