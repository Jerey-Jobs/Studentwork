//找出1000以内的完数
#include<stdio.h>
int main()
{
    int i, j, s;
    for(i = 2; i < 1000; i++)
        {   
            s=0;
            for(j = 1; j < i; j++)
            {
                if((i%j) == 0)
                s = s + j;
            
            }
            if(s == i)
            printf("%d ",i);
        }
    printf("\n");
return 0;
}
