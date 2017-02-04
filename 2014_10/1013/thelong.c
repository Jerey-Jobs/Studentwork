#include <stdio.h>

/*将str字符串中的＊str前面的len长度部分拷贝进point所指的字符串 */
int my_strcpy(char *point, char *str, int len)
{
    while(len > 0)                 
    {
        *point = *str;           //str前面第len个赋值给point所指第一个字符
        point++;                 //point指针向后一个
        str++;                   //str指针向后一个
        len--;                   //len减少,从而实现len个字符的复制
    }

    *point = '\0';               //在字符数组最后一个加‘\0’

    return 0 ;
}

/*找出最长数字子串并调用my—strcpy函数将最长字串复制给output指向的字符串*/
int continuemax(char *str, char *output)
{ 
    int count = 0;               //count计数每个数字子串的长度
    int max = 0;                 //max为最长的数字子串长度

    while(*str != 0)
    {
        while(*str >= '0' && *str <= '9')       //判断一个字符是否为数字
        {
            str++;
            count++;
        }
		
        if (count > max)          //如果该count子串为最长则max＝count，并实现子串的复制
        {
            max = count;
            my_strcpy(output, str - max, count);
        }

        count = 0;                //在每次用完count将它清0
		
        str++;
    }

    return max;                   //返回一个整形max 为最长数字子串的长度
}


int main()
{
    char str[100];                //str为输入字符串
    char ptr[100];                //ptr为输出的最长字符串
    int a;                        //a为最长数字字串长度

    printf("input a string: "); 
    scanf("%s", str);

    a = continuemax(str, ptr);

    printf("the max number = %d\n", a);               //输出最长数字子串的长度
    printf("the max string = %s\n", ptr);     //输出最长数字字串 
	
    return 0;
}
