//将句子中单词位置倒置，但不改变单词结构
#include<stdio.h>
#include<string.h>
int main()
{
    int turn(char s[]);
    char str[100];
    char tmp[100];
    int i=0, c;
    printf("输入一句话：");
    gets(str);
    turn(str);
    for(i; str[i] != '\0'; i++)
      {   
          if(str[i]==' ')
          {   turn(tmp);
              puts(tmp);
              printf(" ");
          }
              tmp[i]=str[i];
         

    }
return 0;
}

int turn(char s[])
{
    char tmp;
    int  i, j, n, m;
    n=strlen(s);
    m=(n-1)/2;
    for(i = 0; i <=m ;i++)
    {
        j=n-1-i;
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
    printf("到过来为: %s",s);
    printf("\n");
return;
}


