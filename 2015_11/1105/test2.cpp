#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 5;
	int b = 6;
	swap(a,b);
	cout<<a<<"||"<<b<<endl;
}
	
