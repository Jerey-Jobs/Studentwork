#include <stdio.h>

#define MAX 100

char * my_strchr(const char *src, int c)
{
    char *temp = NULL;

    while(*src != '\0')
    {
        if(*src == c)
	{
	    temp = src;
	}

	src++;
    }

    return temp;
}

char * my_strstr(const char *src, const char *dest)
{
    int flag;
    char *tmp_src = NULL;
    char *tmp_dest = NULL;
    
    while(*src != '\0')
    {
        tmp_src = src;
        tmp_dest = dest;

	flag = 0;

	while(*dest != '\0')
	{
	    if(*src != *dest)
	    {
                flag = 1;
	    }

	    dest++;
	    src++;
	}
        
        if(flag == 0)
	{
	    return tmp_src;
	}

	src = tmp_src;
	dest = tmp_dest;

	src++;
    }

    return NULL;


}

int main()
{
    char ch;
    char src[MAX];
    char dest[MAX];

    printf("Please input source string:\n");
    scanf("%s",src);

    printf("Please input aim char:\n");
    getchar();
    scanf("%c",&ch);

    printf("strchr:%s\n",my_strchr(src,ch));

    printf("Please input dest string:\n");
    scanf("%s",dest);

    printf("strstr:%s\n",my_strstr(src,dest));

    return 0;
}
