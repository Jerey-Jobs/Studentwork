#include<stdio.h>
#include<string.h>

int main()
{
    int num = 123456789;                      
    char str[100];                  //输出结果
    char temp;                      //中间变量
    int i = 0;
    
    /*number to string */
    while(num > 0)
    {
        str[i] = num % 10 + '0';   //eg:12 % 10 = 2  then  '2' = 2 + '0' 
        num = num / 10;              
        i++;                       //进行下一个字符
    }
    
    str[i] = '\0';                 //字符串结尾＋'\0'

    int len = strlen(str);  

    /*头尾调换，'\0'除外*/ 
    for(i = 0; i < len / 2; i++)
    {  
        temp = str[i];
        str[i] = str[len - 1 - i]; 
        str[len - 1 - i] = temp;
    }

    printf("%s",str);       
    
    return 0;                      
} 
