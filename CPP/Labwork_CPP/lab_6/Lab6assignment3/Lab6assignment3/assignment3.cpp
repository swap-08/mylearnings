/*************************<File Header>*************************/
/*!
@file: assignment3.cpp
@brief Abstract: Use of inheritance to calculate area of rectangle
and triangle
Author: Swapnil Kadam
Date:05/12/2013
*/
/*****************************************************************/

#include"assignment3.h"

void main()
{
	Shape *s;			//base class object pointer
	Rectangle r;		//derived class object
	s=&r;				//assigning address of rectangle object to object pointer

	int side1,side2;

	cout<<"Enter first side :"<<endl;
	cin>>side1;

	cout<<"Enter second side :"<<endl;
	cin>>side2;

	s->getData(side1,side2);
	s->displayArea();

	Triangle t;			//derived class object
	s=&t;				//assigning address of triangle object to object pointer

	s->getData(side1,side2);
	s->displayArea();
}