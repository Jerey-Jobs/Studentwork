#include<stdio.h>
int main()
{
    char *intstr(int);                  //函数申明
    int n;                              //定义字符n

    printf("输入一个数字：");
    scanf("%d",&n);
	
    printf("print : %s\n", intstr(n));
	
    return 0;
}

/*intstr函数将整型n转换为一个字符串，并返回一个字符串的指针str */
char *intstr(int n)
{
    static char str[32];                //定义静态变量str字符数组
    int tmp;                            //tmp为临时变量
    int i = 0;                           
    int j;

    while (n > 0)                       //对n进行操作，取出n每一位
    {
        tmp = n % 10;
        str[i] = tmp + '0';               //通过加字符‘n’实现将整型转为字符型
        n = n / 10;
        i++;
    }
	
    str[i] = '\0';                        //最后一个字符赋值‘\0’
	
    i--;                                //i就为str数组里的字符个数，i－－便于下面
                                        //进行 除最后一位字符之外的倒序

    for (j = 0; j < (i / 2); j++)       //倒序字符数组
    {
        tmp = str[j];
        str[j] = str[i - j];
        str[i - j] = tmp;
    }

    return str;                          //将字符数组指针str返回
}
