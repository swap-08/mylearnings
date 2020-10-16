/*************************<File Header>*************************/
/*!
@file: assignment2.cpp
@brief Abstract: Implement a function to add two complex numbers
Author: Swapnil Kadam
Date:3/12/2013
*/
/*****************************************************************/
#include"assignment2.h"
complex::complex(float x,float y)
{
	real=x;
	imag=y;
}

complex::complex(complex &x)		//copy constructor
{
	real=x.real;
	imag=x.imag;
}
float complex::getImag()
{
	float imag;
	cout<<"Enter imaginary part"<<endl;
	cin>>imag;
	return imag;
}
float complex::getReal()
{
	float real;
	cout<<"Enter real part"<<endl;
	cin>>real;
	return real;
}
complex& complex::add(complex x,complex y)
{
	complex t;
	t.real=x.real+y.real;		//+t.real;
	t.imag=x.imag+y.imag;		//+t.imag;
	return t;
}
void complex::increment()
{
	real++;
	imag++;
}
void complex::print()
{
	cout<<"Real part  :"<<real<<endl;
	cout<<"Imaginary part   :"<<imag<<endl;
}

void main()
{
	float real,imag;

	complex c(2.2,2.5),c1,c2,c3;	//,c4(real,imag);
	real=c1.getReal();
	imag=c1.getImag();
	c.print();
	complex c4(real,imag);
	c2=c3.add(c,c4);
	c2.print();
}