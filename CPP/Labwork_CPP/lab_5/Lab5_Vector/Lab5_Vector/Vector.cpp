/*************************<File Header>*************************/
/*!
@file: Vector.cpp
@brief Abstract: Create a class structure for operator overloading
Author: Swapnil Kadam
Date:3/12/2013
*/
/*****************************************************************/
#include<iostream>
#include"Vector.h"
using namespace std;
//class member functions definition

CVector::CVector(int a,int b)			//parameterised constructor
{
	x=a;
	y=b;
}


CVector CVector::operator +(CVector param)			//operator overloading
{
	CVector temp;
	temp.x=x+param.x;
	temp.y=y+param.y;
	return (temp);	
}


void CVector::display()				//display x and y
{
	cout<<"x  :"<<x<<"   "<<"y  :"<<y<<endl;
}


void main()
{
	CVector a(3,1);
	CVector b(1,2);

	CVector c;			//object created as default constructor

	c=a+b;				//operator overloading function calling

	cout<<"The addition of the vector is"<<endl;
	c.display();
}