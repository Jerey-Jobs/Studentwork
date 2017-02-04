/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>


int small_10(char *p,int n)
{
    int result = 0;
	while(*p != '\0')
	{
        result = result * n + *p - '0';
        p++;
	}

	return result;
}

int large_10(char *p,int n)
{
    int result = 0;
	while(*p != '\0')
	{
		if(*p >= 'A')
		{
            result = result * n + *p - 'A' + 10;
        }
        else
        {
        	result = result * n + *p - '0';
        }
        p++;
	}

	return result;
}


int main()
{
	char c[100];
    int n;

    scanf("%s%d",c,&n);

    int result;

    if(n < 10)
    {
        result = small_10(c,n);
    }
    else
    {
    	result = large_10(c,n);
    }

    printf("%d",result);
     
    return 0;
}
