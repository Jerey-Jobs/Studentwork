#include <iostream>
#include <cstring>
using namespace std;

class Person{
protected:
	int age;
	char name[20];
public:
	Person(int n,char *str);
	Person();
	~Person();
	virtual void display();
};

Person::Person(){}
Person::Person(int n,char *str):age(n)
{
	strcpy(this->name,str);
}
Person::~Person()
{
	cout<<"person gone"<<endl;
}
void Person::display()
{
	cout<<"person__"<<age<<"||"<<name<<endl;
}


class Stu: public Person{
public: 
	Stu(int n,char *name):Person(n,name){}
	void display()
	{
		cout<<"stu__"<<age<<"||"<<name<<endl;
	}
};


int main()
{
	Person *p = new Person(12,"xiamin");
	
	p->display();
	
	return 0;
}
