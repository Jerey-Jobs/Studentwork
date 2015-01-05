#include<stdio.h>
int main()
{
    int a[10];
    int i, j, temp;
    printf("shuru:");
    for(i = 0; i < 10; i++ )
        scanf("%d", &a[i]);
    for(i = 0; i < 9; i++ )
        for(j = 0; j < 9-i; j++)
            if(a[j] > a[j+1] )
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    printf("\nnow");
    for(i = 0; i < 10; i++ )
        printf(" %d ", a[i] );
    printf("\n");
return 0;
}

    
