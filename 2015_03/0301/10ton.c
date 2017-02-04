/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
	int num,n;

	scanf("%d%d",&num,&n);

	char c[100];
	int i = 0;
	int flag;

    while(num != 0)
    {
        flag = num % n;

        if(flag >= 0 && flag <= 9)
        {
        	c[i] = flag + '0';
        }
        else if(flag > 9)
        {
        	c[i] = flag - 10  + 'A';
        }

        num = num / n;
        i++;
    }

    c[i] = '\0';

    int len = strlen(c);
    char tmp;

    for(i = 0; i < len / 2; i++)
    {
        tmp = c[i];
        c[i] = c[len - 1 -i];
        c[len - 1 - i] = tmp;
    }

    printf("%s",c);

    return 0;
}
