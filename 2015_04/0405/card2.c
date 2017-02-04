#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	int j = 0;
	int a[13] = {0};
	int n = 0;
    int setnum = 0;

    for(i = 0; i < 13; i++)
	{
	    a[i] = 0;
	}
    
    for(i = 0; i < 13; i++)
    {
        n = 0;
        while(n < 13)
        {
            if(j > 12)
            {
                j = 0;
            }
            
            if(a[j] != 0)
            {
                j++;
            }
            else{
                if(n == i)
                {
                    a[j] = i + 1;
                }
                j++;
                n++;
            }
        }

    }

    for(i = 0; i < 13; i++)
    {
    	printf("%d ",a[i]);
    }

    getchar();
    getchar();

	return 0;
}
