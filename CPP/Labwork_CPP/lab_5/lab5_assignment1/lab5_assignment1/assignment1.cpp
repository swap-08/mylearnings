/*************************<File Header>*************************/
/*!
@file: assignment1.cpp
@brief Abstract: Write a complex number class with overloaded
operators
Author: Swapnil Kadam
Date:3/12/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;

class ComplexNumber
{
private: float real,imag;
public: ComplexNumber()			//default constructor
		{
			real=0;
			imag=0;
		}

		ComplexNumber(float x,float y)		//parameterised constructor
		{
			real=x;
			imag=y;
		}


		void operator +(ComplexNumber &x)		//operator overloading member function addition operator
		{
			ComplexNumber t;
			t.real=real+x.real;
			t.imag=imag+x.imag;
			t.print();
		}
	
		
		void operator -(ComplexNumber &x)			//operator overloading member function subtraction operator
		{
			ComplexNumber t;
			t.real=real-x.real;
			t.imag=imag-x.imag;
			t.print();
		}


		void operator *(ComplexNumber &x)		//operator overloading member function multiplication operator
		{
			ComplexNumber t;
			t.real=real*x.real-imag*x.imag;
			t.imag=real*x.imag+imag*x.real;
			t.print();
		}


		void operator ==(ComplexNumber &x)		//operator overloading member function equality operator
		{
			if(real==x.real && imag==x.imag)
				cout<<"TRUE"<<endl;
			else
				cout<<"FALSE"<<endl;
		}


		void operator !=(ComplexNumber &x)		//operator overloading member function not equal operator
		{
			if(real!=x.real && imag!=x.imag)
				cout<<"TRUE"<<endl;
			else
				cout<<"FALSE"<<endl;
		}


		void operator +=(ComplexNumber &x)		//operator overloading member function addition operator
		{
			ComplexNumber t;
			real=real +x.real;
			imag=imag+x.imag;
			print();
		}


		void operator -=(ComplexNumber &x)		//operator overloading member function subtraction operator
		{
			ComplexNumber t;
			real=real-x.real;
			imag=imag-x.imag;
			print();
		}


		void operator *=(ComplexNumber &x)		//operator overloading member function multiplication operator
		{
			real=real*x.real;
			imag=imag*x.imag;
			print();
		}

		void print()		//display real and imaginary number
		{
			cout<<real<<" "<<imag<<"i"<<endl;
		}

};	//end of class


void main()
{
	ComplexNumber c1(4.2,8.3),c2(3.1,-9.2);		//object creation
	c1.print();
	c2.print();

		//calling operator overloading member functions 

	cout<<"C1+C2   :";
	c1+c2;
	
	cout<<"C1-C2   :";
	c1-c2;
	
	cout<<"C1*C2   :";
	c1*c2;
	
	cout<<"C1==C2  :";
	c1==c2;
	
	cout<<"C1!=C2  :";
	c1!=c2;
	
	cout<<"C1+=C2  :";
	c1+=c2;
	
	cout<<"C1-=C2  :";
	c1-=c2;
	
	cout<<"C1*=C2  :";
	c1*=c2;
}