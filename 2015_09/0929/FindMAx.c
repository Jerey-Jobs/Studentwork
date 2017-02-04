#include <stdio.h>

int findmax(int a[], int n)
{
    int i;
    int tmp = 0;
    int max = -99;
    int k = 1;
    int start, end;

    for(i = 1; i < n; i++)
    {
        tmp += a[i];
        if(tmp > max)
        {
            max = tmp;
            start = k;
            end = i;
        }
        if(tmp < 0)
        {
            tmp = 0;
            k = i + 1;
        }
    }

    printf("%d %d\n", start, end );
    return max;
}

int main(int argc, char const *argv[])
{
    int a[10] = {7, 2, -4, -6, 2, 5, 1, 8, -3};

    printf("%d\n", findmax(a, 9));

    return 0;
}

