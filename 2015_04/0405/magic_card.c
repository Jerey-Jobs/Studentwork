#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	int a[13] = {0};
	int count = 0;
    int setnum = 0;
    int n = 0;

    for(i = 0; i < 13; i++)
	{
	    a[i] = 0;
	}
    
    while(setnum != 12)
    {
        n = 0;
        for(i = 0; i < 13; i++)
        {
			if(count > 13)
			{
                count = count % 13;            
			}

            if(a[count] != 0)
            {
				count++;		
            }
			else
            {
                count++; 
                
			    n++;
                if(n == i)
				{
                    a[count] = i;            
				}
			}
        }
        setnum++;    
    }

    for(i = 0; i < 13; i++)
    {
    	printf("%d ",a[i]);
    }

    getchar();
    getchar();

	return 0;
}

