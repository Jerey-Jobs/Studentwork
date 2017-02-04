/**
 * @author evan lau
 * @date   2015/06/13
 */

#include <stdio.h>

int main(int argc, char **argv)
{
    printf("argc=%d\n", argc);
    int i;
    for (i = 0; i < argc; i++)
    	printf("argv[%d] = %s\n", i, argv[i]);

    return 0;
}



