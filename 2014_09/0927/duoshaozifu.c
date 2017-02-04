//我输入一句话有多少单词
#include<stdio.h>
int main()
{
    char string[100], c;
    int i, num = 0;
    gets(string); //因为scanf遇到空格输入就结束了。。
    for(i = 0; string[i] != '\0'; i++)
         if ( string[i] != ' '&& string[i+1]== ' ' )
            num++;
         else if(string[i] != ' '&&string[i+1]=='\0' )
            num++;
    printf("number is %d\n", num);
return 0;
}


