#include <stdio.h>

int start;
int end;

int FindMax(char *a)
{
    int count = 0;
    int max = 0;
    int i = 0;
    while(*a != 0)
    {
        if(*a <= '9' && *a >= '0')
        {
            count++;
            if(count > max)
            {
                end = i;
                max = count;
                start = end - max;
            }
        }
        else
        {
            count = 0;
        }
        a++;
        i++;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    char *a = "gdsgf3124fdgh3256532dsv353456465dsf1231f";

    printf("%d\n", FindMax(a));
    printf("%d %d\n", start, end);

    return 0;
}


