#include <stdio.h>

void ShellSort(int date[], int n)
{
    int d = n;
    int i;
    while(d > 1)
    {
        d = (d + 1) / 2;
        for(i = 0; i < n - d; i++)
        {
            if(date[i + d] < date[i])
            {
                date[i] ^= date[i + d];
                date[i + d] ^= date[i];
                date[i] ^= date[i + d];
            }
        }

        for(i = 0; i < n; i++)
        {
            printf("%d ", date[i]);
        }
        printf(" \n");
    }
}

void ShellSort1(int date[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(date[i + 1] < date[i])
        {
            date[i] ^= date[i + 1];
            date[i + 1] ^= date[i];
            date[i] ^= date[i + 1];
        }
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", date[i]);
    }
    printf(" \n");
}

int main(int argc, char const *argv[])
{
    int a[10] = {534, 2, 51, 65, 23, 21, 43, 65, 76, 3};

    ShellSort1(a, 10);

    return 0;
}

