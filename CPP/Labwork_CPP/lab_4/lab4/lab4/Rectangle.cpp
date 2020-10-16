/*************************<File Header>*************************/
/*!
@file: Rectangle.cpp
@brief Abstract: Write a program to change width and height of 
rectangle object and find area of rectangle with new values
Author: Swapnil Kadam
Date:30/11/2013
*/
/*****************************************************************/
#include"Rectangle.h"
void CRectangle::setValues(int a,int b)
{
	height=a;
	width=b;
}
int CRectangle::Area(void)
{
	int result=height*width;
	return result;
}

CRectangle duplicate(CRectangle rectparam)
{
	CRectangle rectres;
	rectres.width=rectparam.width*2;
	rectres.height=rectparam.height*2;
	return rectres;
}
void main()
{
	CRectangle rect1,rect2;
	rect1.setValues(2,3);
	rect2=duplicate(rect1);

	cout<<"Area rect1:   "<<rect1.Area()<<endl;
	cout<<"Area rect 2:  "<<rect2.Area()<<endl;
}