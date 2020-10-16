/*************************<File Header>*************************/
/*!
@file: MyClass.cpp
@brief Abstract: Create a header file and object of the class
Author: Swapnil Kadam
Date:29/11/2013
*/
/*****************************************************************/
#include "MyClass.h"
void main()
{
	MyClass m_class1;
	m_class1.setMyData(10);
	int iData;
	iData=m_class1.getMyData();
	cout<<"My Data is"<<iData<<endl;
}
