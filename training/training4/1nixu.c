//实现一个字符串的逆向输出
#include<stdio.h>
int main()
{
    char str[100];
    int i ,j = 0;
    printf("输入: ");
    scanf("%s",str);
    for(i = 0; str[i]!='\0'; i++)
            j++;
    printf("shuchu: ");
    for(i = j; i > 0; i--)
        printf("%c",str[i]);
    printf("\n");

return 0;
}
