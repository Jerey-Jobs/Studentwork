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
    int x1;
    int x2;
    int y1;
    int y2;

    float tmp;
    float result;

    int count = 0;

    for(x1 = 1; x1 < 10; x1++)
    {
        for(x2 = 1; x2 < 10; x2++)
        {
            for(y1 = 1; y1 < 10; y1++)
            {
                for(y2 = 1; y2 < 10; y2++)
                {
                    if(x1 == y1 || x2 == y2)
                    {
                        continue;
                    }
                   if((float)(x1 * 10 + x2)*1.0 / (y1 * 10 + y2) == (float)x1 * x2 * 1.0/ (y1 * y2))
                   {
                       tmp = x1 * x2 * 1.0 / (y1 * y2);
                        
                        count++;
                        printf("tmp%d = %f %d %d %d %d\n",count,tmp,x1,x2,y1,y2);
                    }
                }
            }
        }
    }

    printf("%d\n",count);


    return 0;
}
