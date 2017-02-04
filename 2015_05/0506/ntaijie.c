/*一只青蛙一次可以跳上 1 级台阶，
也可以跳上2 级。求该青蛙跳上一个n 级的台阶总共有多少种跳法。*/


#include <stdio.h>

int n;
int count = 0;


int get(int t)
{
    if(t <= 0)
    {
    	return 0;
    }

    if(t == 1)
    {
    	return 1;
    }
    
    if(t == 2)
    {
        return 2;    
    }
    
    return get(t - 1) + get(t - 2);
}


int main(int argc, char const *argv[])
{
	int a;

	scanf("%d",&a);

   printf("%d\n",get(a));

	getchar();
	getchar();

	return 0;
}



