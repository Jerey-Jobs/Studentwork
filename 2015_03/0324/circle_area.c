#include <stdio.h>

#define PI 3.14159265358979323

int main()
{
	double n;
	double m2;

    scanf("%lf",&n);
	
	m2 = PI * n * n;

	printf("%.7lf\n", PI * n * n);
}

