/*************************<File Header>*************************/
/*!
@file: Construct.cpp
@brief Abstract: Write a program to calculate area of the rectangle
using constructor and destroying a rectangle object
Author: Swapnil Kadam
Date:02/12/2013
*/
/*****************************************************************/
#include"Construct.h"
CRectangle::CRectangle()		//default constructor
{
	width=0;
	height=0;
}
CRectangle::CRectangle(int a,int b)		//parameterised constructor
{
	width=a;
	height=b;
}
int CRectangle::area(void)
{
	int result;
	result=height*width;
	return result;
}
int main()
{
	CRectangle recta;			//default constructor calling
	CRectangle rect(3,4);		//parameterised constructor calling
	CRectangle rectb;			//default constructor calling	
	
	cout<<"React area"<<rect.area()<<endl;			//parameterised constructor calling
	cout<<"Reactb area"<<rectb.area()<<endl;		//default constructor calling
	cout<<"Reacta area"<<recta.area()<<endl;		//default constructor calling
}