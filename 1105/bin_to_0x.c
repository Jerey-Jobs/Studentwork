/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>


int bin20x(int n,char *p)
{
    int tmp;
    char *flag = p;

    while(n > 0)
    {
        tmp = n % 16;

        if(tmp >= 0 && tmp <= 9)
        {
            *p = tmp + '0';
        }
         
        if(tmp > 9)
        {
            *p = tmp - 10 + 'A';
        }

        n = n / 16;
        p++;
    }

    *p = '\0';

    p = flag;

    char temp;
    int len = strlen(p);
    int i;

    for(i = 0; i < len / 2; i++)
    {
        temp = *(p + i);
        *(p + i) = *(p + len - 1 - i);
        *(p + len - 1 - i) = temp;
    }

    
}

int main()
{
    long int num;
    char str[100];   

    printf("please input the number : ");
    scanf("%d",&num);

    bin20x(num,str);

    printf("the 0x of the number is : Ox%s\n",str);
    
    return 0;
}
