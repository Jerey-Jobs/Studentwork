#include <stdio.h>

char a[100][100];
int n;
int count;

void sort(char *p)
{
	count = 0;

    int min;
    int i;
    int j;
    int tmp;
    int len = strlen(p);

    for(i = 0; i < len -1; i++)
    {
        min = i;

        for(j = i + 1; j < len; j++)
        {
            if(*(p + min) > *(p + j))
            {
                min = j;
             
            }
        }

        if(i != min)
        {
            tmp = *(p + i);
            *(p + i) = *(p + min);
            *(p + min) = tmp;
            count++;
        }
        
    }

    printf("%d\n",count);

}


int main(int argc, char const *argv[])
{
	scanf("%d",&n);

	int i;

	for(i = 0; i < n; i++)
	{
         scanf("%s",a[i]);
	}

    for(i = 0; i < n; i++)
    {
    	sort(a[i]);
    }

	return 0;
}


