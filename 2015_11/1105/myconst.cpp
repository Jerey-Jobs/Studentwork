#include <iostream>
#include <cstring>
using namespace std;

class Stu{
private:
	int num;
	char *str;
public:
	Stu();
	Stu(int n,char *s);
	int getnum() const;
	char *getstr() const;
};

class SStu: public Stu{
public:
	SStu(int n,char *s):Stu(n,s){}
	
};

Stu::Stu(){}
Stu::Stu(int n,char *s):num(n)
{
	this->str = s;
//	strcpy(str,s)#8B8082;#8D7676#777373
}
int Stu::getnum() const
{
	return num;
}
char *Stu::getstr() const
{
	return str;
}

int main(int argc, char **argv)
{
	Stu *m = new SStu(5,"xi");
	cout<<m->getnum()<<"|"<<m->getstr()<<endl;
	return 0;
}

