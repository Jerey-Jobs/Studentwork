//输出100以内的所有素数
#include<stdio.h>
//#include<math.h>
int main()
{
   int scan(int t);
   int  i, s;
   for(i = 2; i <= 100; i++)
   {
       s = scan(i);
       if(s == 0)
       printf("%d ",i);
   }
   printf("\n");
    return 0;
}

int scan(int t)  //判断这个数是不是素数,不是的话则b为1
{
    int a , m ,b =0;
    m = t;
    for(a = 2; a < m; a++)
    {
       if (t%a==0) b=1;    
    }
    return b ;   
}
