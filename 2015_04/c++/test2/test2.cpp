// test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "c_student.h"
#include <iostream>
using namespace std;

int count;

int main(int argc, char* argv[])
{
	c_student stu1(2);
	cout<<stu1.getage()<<endl;
    
	return 0;
}
