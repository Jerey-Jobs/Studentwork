/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 5

int insert_order(int *p)
{
    int tmp;
    int i;
    int j;
    
    for(i = 1; i < MAX; i++)
    {
        tmp = *(p + i);
        j = i;

        while(tmp < *(p + j - 1))
        {
            *(p + j) = *(p + j -1);
            j--;
        }
        
        *(p + j) = tmp;
    }

}

int main()
{
    int i;
    int a[MAX];

    printf("please input 5 num :");
    for(i = 0; i < MAX; i++)
    {
        scanf("%d",&a[i]);
    }
 
    insert_order(a);

    printf("ordering 5 number is :");
    for(i = 0; i < MAX; i++)
    {
        printf("%d  ",a[i]);
    } 
    printf("\n");

    return 0;
}
