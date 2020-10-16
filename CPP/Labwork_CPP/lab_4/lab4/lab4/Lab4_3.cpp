/*************************<File Header>*************************/
/*!
@file: Lab4_3.cpp
@brief Abstract: Write a program to convert a square object into
a square object into a rectangle object using friend class
Author: Swapnil Kadam
Date:30/11/2013
*/
/*****************************************************************/
#include"Lab4_3.h"
void CRectangle::convert(CSquare a)
{
	width=a.side;
	height=a.side;
}
int main()
{
	CSquare sqr;
	CRectangle rect;
	sqr.set_side(4);
	rect.convert(sqr);
	cout<<"Area after a square converted to the rectangles is"<<endl;
	cout<<rect.area()<<endl;
	return 0;
}