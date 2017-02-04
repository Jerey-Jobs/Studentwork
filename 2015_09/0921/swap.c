#include <stdio.h>


int main()
{
	int a = 3;
	int b = 5;
	 printf("%d %d\n",a,b);
	 a ^= b;
	 printf("%d %d\n",a,b);
	 b ^= a;
	 printf("%d %d\n",a,b);

	 a ^= b;
	 printf("%d %d\n",a,b);

	 a^=b^=a^=b;
	 printf("%d %d\n",a,b);

	 return 0;
}