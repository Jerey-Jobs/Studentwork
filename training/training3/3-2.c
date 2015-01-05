//利用字符数组实现一个先入后出的盏结构。。提供push和pop接口。
#include<stdio.h>
int main()
{
    int n=100;
    char c[100]={0,0};
    int i;
    char s[n];
    printf("入栈：");
    gets(s);
    for(i = 0; s[i] != '\0'; i++)
    {
        c[n-1]=s[i];
            n--;
    }



    printf("出栈：");
    for(n; n < 100; n++)
    {
        printf("%c",c[n]);
    }
    printf("\n");
    return 0;
}
