// c_student.h: interface for the c_student class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_C_STUDENT_H__FDC6EBC1_45BB_46DD_B969_ECA8E1B953FD__INCLUDED_)
#define AFX_C_STUDENT_H__FDC6EBC1_45BB_46DD_B969_ECA8E1B953FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class c_student  
{
	int age;
	char name[20];
public:
	c_student();
	c_student(int age);
	virtual ~c_student();
	int getage();

};

#endif // !defined(AFX_C_STUDENT_H__FDC6EBC1_45BB_46DD_B969_ECA8E1B953FD__INCLUDED_)
