/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

int sum0xf(int n)


int bin20x(int n,char *p)
{
    int i;
    int tmp;
    int sum;
    char *flag = p;
    
    for(i = 0; i < 8; i++)
    {
        tmp = n && 0xf;
        
        
        
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
