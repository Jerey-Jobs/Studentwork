/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int count = 0;

int func(int n)
{
	int i;
    count++;
	
    for(i = 1; i <= n / 2; i++)
	{
        func(i);
	}
}


int main()
{
	int num;

	scanf("%d",&num);

	func(num);

	printf("%d",count);

    return 0;
}
