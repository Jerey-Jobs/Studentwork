#include "stdio.h"

int main(int argc, char const *argv[])
{
    int flag = 0;
    char password[10];
    memset(password, 0, sizeof(password));
    strcpy(password, argv[1]);

    if (0 == strcmp("LinuxGeek", password))
    {
        flag = 1;
    }

    if (flag)
    {
        printf("cracked\n");
    }
    else
    {
        printf("in\n");
    }
    printf("%d\n", flag);
    return 0;
}
