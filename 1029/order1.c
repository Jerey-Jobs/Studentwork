/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

void sort(int *p)
{
    int min;
    int i;
    int j;
    int tmp;

    for(i = 0; i < 4; i++)
    {
        min = i;

        for(j = i + 1; j < 5; j++)
        {
            if(*(p + min) > *(p + j))
            {
                min = j;
            }
        }


    //    printf("%d\n",__LINE__);

        if(i != min)
        {
            tmp = *(p + i);
            *(p + i) = *(p + min);
            *(p + min) = tmp;
        }
        
    //    printf("%d\n",__LINE__);
    }
    
        printf("%d\n",__LINE__);
}

int main()
{
    int num[5];
    int i;

    printf("please input 5 number : ");
    for(i = 0; i < 5; i++)
    {
        scanf("%d",&num[i]);
    }

    sort(num);

    printf("output:");
    for(i = 0; i < 5; i++)
    {
        printf("%d ",num[i]);
    }

    return 0;  
}
