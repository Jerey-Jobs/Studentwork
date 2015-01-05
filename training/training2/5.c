//使用异或运算生成一个新的32位整数b 
int main()
{
    int a, b;
    int n[32], m[32];
    int i ;
    printf("输入一个整数a：");
    scanf("%d",&a);
    for(i = 0; i < 32; i++)
    {
        n[i]=a%2;
        a=a/2;
    }
    printf("a的二进制：");
        for(i = 31; i >= 0; i--)
        {
        printf("%d",n[i]);
        }
    printf("\n");    

    for(i = 1; i < 31; i++)
    {   
        m[i]=n[i-1]^n[i+1];
    }
    m[0]=0^n[1];
    m[31]=n[30]^0;
    printf("b的32位为：");
    for(i = 31; i >= 0; i--)
    {
        printf("%d",m[i]);
    }
    printf("\n");
return 0;
}
