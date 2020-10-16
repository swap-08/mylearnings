/*************************<File Header>*************************/
/*!
@file: Polygon.cpp
@brief Abstract: Inheritance
Author: Swapnil Kadam
Date:04/12/2013
*/
/*****************************************************************/
#include"Polygon.h"
int main()
{
	//Objects creation of derived class

	CRectangle rect;
	CTriangle trgl;

	rect.set_values(4,5);
	trgl.set_values(4,5);	

	cout<<"Area of Rectangle  :";
	cout<<rect.area()<<endl;

	cout<<"Area of Triangle  :";
	cout<<trgl.area()<<endl;
	
	return 0;
}