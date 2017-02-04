#include <stdio.h>

int a[10];
int book[10];
int result[5];

int dfs(int n)
{
	int i;
    if(n == 5)
    {
    	for(i = 0; i < 5; i++)
		{
		    printf("%d",result[i]);
		}
		printf("\n");
    }

    for(i = 0; i < 5; i++)
    {
    	if(book[i] == 0)
    	{
    		book[i] = 1;
    		result[n] = a[i]; 
    		dfs(n + 1);
    		book[i] = 0;
    	}
    }

}



int main(int argc, char const *argv[])
{
	int i;
	for(i = 0; i < 5; i++)
	{
	    scanf("%d",&a[i]);
	}

	dfs(0);
    
    getchar();
getchar();
	return 0;
}
