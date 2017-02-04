/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
    int y;
    float x;
    float n;
    
    for(y = 10; y >= -10; y--)
    {
        for(x = 1; x < 64; x++)
        {
            n = sin(x / 10) * 10 - y;
            
            if(n <= 1 && n > 0)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
