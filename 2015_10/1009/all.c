#include <stdio.h>

int a[6];
int book[6];
int count;

int dfs(int n[], int step)
{
    int i;
    if(step == 6)
    {
        // for(i = 0; i < 6; i++)
        // {
        //     printf("%d", a[i]);
        // }
        // printf(" \n");
        count++;

        return;
    }

    for(i = 0; i < 6; i++)
    {
        if(book[i] == 0)
        {
        	book[i] = 1;
            a[step] = n[i];
            dfs(n, step + 1);
            book[i] = 0;
        }
    }

}

int main(int argc, char const *argv[])
{
    int n[6] = {1, 2, 2, 3, 4, 5};

    dfs(n, 0);

    printf("%d\n",  count);

    return 0;

}

