#include<stdio.h>
int main()
{
    int str2int(char *str);          //申明str2int子函数
    char str[100];                   //str存放输入的字符串

    printf("input a string :");
    gets(str);

    printf("output = %d\n", str2int(str));
	
    return 0;
}

/*str2int实现将字符串转换为整形 */
int str2int(char *str)
{
    int s = 0;                       //s是将要返回的整形的值
    int i;                           
    int j;                           //j用来作中间替换用

    for(i = 0; *(str + i) != '\0'; i++)
    {
        j = *(str + i) - '0';          //j为str所指字符变成整形后的值
        s = s * 10 + j;              //实现每一个j的输入，构成整形数
    }
    return s;                        
}
