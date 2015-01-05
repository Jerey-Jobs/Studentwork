//排序
#include<stdio.h>
int main()
{   
    float a[5];
    int i, j, t;
    printf("请输入5个数: ");
    for(i = 0; i < 5; i++)
        scanf("%f",&a[i]);
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4-i; j++)
        {
            if(a[j]>a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    for(i = 0; i < 5; i++)
        printf("%g ",a[i]);

    printf("\n");
    
    return 0;
}
