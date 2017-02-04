/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int count1(int n)
{
    int i;
    int tmp;
    int count = 0;

    for(i = 0; i < 32; i++)
    {
        tmp = n & 1;

        if(tmp == 1)
        {
            count++;
        }

        n = n >> 1;
    }

    return count;
}

int dest2bin(int n,int *p)
{
    int i;
    
    for(i = 0; i < 32; i++)
    {
        *p = n % 2;
        n = n / 2;
        p++;
    }
}

int main()
{
    int i;
    int num;
    int bin[32] = {0};
    int count;



    printf("please input the number : ");
    scanf("%d",&num);

    count = count1(num);

    dest2bin(num,bin);

    printf("the count of 1 is: %d\n",count);

    printf("the bin of the number is : ");
    for(i = 31; i >= 0; i--)
    {
        printf("%d",bin[i]);
    }
    printf("\n");
    
    return 0;
}
