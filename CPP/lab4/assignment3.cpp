/*************************<File Header>*************************/
/*!
@file: assignment3.cpp
@brief Abstract: Use of copy constructor
Author: Swapnil Kadam
Date:30/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
class point
{
	private:
		int x,y,z;
	public:
		point();
		point(int a,int b,int c);
		point(point& i);
		void negate();
		void print();
};

point::point()
{
	x=0;
	y=0;
	z=0;
}
point::point(int a,int b,int c)
{
	x=a;
	y=b;
	z=c;
}

//copy constructor
point::point(point& i)
{
	x=i.x+1;
	y=i.y+1;
	z=i.z+1;
}
void point::negate()
{
 	x=-x;
	y=-y;
	z=-z;
}

void point::print()
{
	cout<<"x  :"<<x<<endl;
	cout<<"y  :"<<y<<endl;
	cout<<"z  :"<<z<<endl;
}


void main()
{
	point p(11,12,13);
	point p1(p);			//copy constructor
	p.print();
	
	p1.negate();
	cout<<"Negate values :"<<endl;
	p.print();
}