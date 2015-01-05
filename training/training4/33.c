//子字符串出现的次数
#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100],c[100];
    int i, j, n, num=0;
    printf("输入字符串a：");
    gets(a);
    printf("输入子字符串b：");
    gets(b);
    n=strlen(b);
    printf("nwei %d\n",n);
    for(i = 0; i < 100; i++)
    {
       if(a[i]=b[0])
        {   for(j = 0; j < n; j++)
            {
                c[j]=a[i+j];
            }
            if (strcmp(b,c)==0)
                num++;
        }
    }
    printf("子字符串的个数：%d\n",num);
return 0;
}

