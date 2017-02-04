#include <stdio.h>

void print(int input,int select)
{
	char buf1[1000000] = {0};
	static char buf2[1000000] = {0};
	buf1[select] += input;
	buf2[select] += input;
	printf("%d %d\n",buf1[select] + input + sizeof(buf1),buf2[select] + input + sizeof(buf2) ); 
}


int main(int argc, char const *argv[])
{
	print(1234,100);
	print(2345,100);	
	return 0;
}

