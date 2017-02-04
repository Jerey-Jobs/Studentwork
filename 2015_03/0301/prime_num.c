/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int my_judge(int num)
{
	int i;
	for(i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
        	return 1;
        }
    }

    return 0;
}

int main()
{
    int i;
    int num;

    scanf("%d",&num);

    if(my_judge(num) == 0)
    {
    	printf("\\t");
    }
    else
    {
    	printf("\\n");
    }
 
    return 0;
}
