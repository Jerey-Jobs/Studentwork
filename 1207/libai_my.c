/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int main()
{
    int a;
    int b;
    int sum;
    int i;
    int count = 0;

    int max = pow(2,14);

    for(i = 0; i < max; i++)
    {
        sum = 2;
        a = 0;
        b = 0;
        int tmp = i;
        int j;
        for(j = 0; j < 14; j++)
        {
            if(sum < 0)
            {
                break;
            }
            
            if(tmp % 2 == 0)
            {
                sum--;
                b++;
            }
            else
            {
                sum = sum * 2;
                a++;
            }
            tmp = tmp>>1;

        }
        if((sum == 1) && (a == 5) &&(b == 9))
        {
            count++;
        }
    }

    printf("pow = %d\n",max);
    printf("count = %d\n",count);
    return 0;
}
