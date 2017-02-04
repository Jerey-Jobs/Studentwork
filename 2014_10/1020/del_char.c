#include <stdio.h>

int main()
{
    int i;
    int count[26] = {0};
    char *src = "linglingaccbd";
    char *tmp = src;
    char dest[100];

    while(*src != '\0')
    {
        count[*src - 'a']++;
	    src++;
    }

    int min;

    for(i = 0; i < 26; i++)
    {
        if(count[i] != 0)
        {
            min = count[i];
        }
    }

    for(i = 0; i < 26; i++)
    {
        if(min > count[i] && (count[i] != 0))
        {
            min = count[i];
        }
    }

    src = tmp;

    i = 0;
    while(*src != '\0')
    {
        if(count[*src - 'a'] > min)
        {
            dest[i] = *src;
            i++;
        }
        src++;
    }
    dest[i] = '\0';

    printf("%s",dest);


    return 0;
}
