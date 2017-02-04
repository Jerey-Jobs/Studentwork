#include <stdio.h>

void Draw()
{
	int i;
    int y;
    int space;
    for(y = 40; y >= 0; y--)
    {
    	for(i = -5; i <= 5; i++)
    	{
    		if( (i*i + 2 *i + 1) != y)
    		{
    			printf("    ");
    		}
    		else
    		{
    			printf("*");
    		}
    	}
    	printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    Draw();
    return 0;
}

