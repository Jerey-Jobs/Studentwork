#include<stdio.h>
//#include"file2.c"
int a;
int main()
{
	int function(int );
	int b = 3;
	int c, d, m;
	printf("输入a m的值：");
	scanf("%d,%d",&a,&m);
	c=a*b;
	printf("c=%d\n",c);
	d=function(m);
	printf("d=%d\n",d);

	return 0;
}

