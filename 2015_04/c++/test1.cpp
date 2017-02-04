
#include <iostream>
using namespace std;

class father
{
	
public:
	int height;

	father()
	{
	}

	father(int num) 
	{
		this->height = num;
	}

    int getheight()
	{
		cout<<"ff输出"<<endl;
		return height;
	}
    virtual void setage(int n)
	{
	}

};

class child:public father
{
private:
	int age;
public:
    child()
	{
	}

	child(int n)
	{
		this->age = n;
	}

	void setage(int n)
		{
		this->age = n;
	}


	int getheight()
	{
		cout<<"孩子输出height"<<endl;
		return height+1;
	}

	int getage()
	{
		cout<<"孩子输出"<<age;
	    return age;
	}

};

int main()
{
	father *a = new child();
	

//	child *b = (child *)a;
//	b->setage(5);
    
	a->setage(5);
	
    getchar();
	getchar();
    return 0;

}
