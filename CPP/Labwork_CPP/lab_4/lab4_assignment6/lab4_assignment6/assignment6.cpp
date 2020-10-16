/*************************<File Header>*************************/
/*!
@file: assignment6.cpp
@brief Abstract: Create a class that emulates a fractional numbr
Author: Swapnil Kadam
Date:30/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
class fraction
{
private:
	int numerator;
	int denominator;
public:
	fraction()
	{
		numerator=0;
		denominator=0;
	}
	fraction(int num,int den)
	{
		numerator=num;
		denominator=den;
	}
	fraction(fraction& i)
	{
		numerator=i.numerator;
		denominator=i.denominator;
	}
	void print()
	{
		cout<<"Numerator  :"<<numerator<<endl;
		cout<<"Denominator  :"<<denominator<<endl;
	}
	friend float add(fraction& a,fraction& b);
	friend float subtract(fraction& a,fraction& b);
	friend float multiply(fraction& a,fraction& b);
	friend fraction inc(fraction& a);
	};
float add(fraction& a,fraction& b)
{
	float temp1=a.numerator*b.denominator+b.numerator*a.numerator;
	float temp2=a.denominator*b.denominator;
	return (temp1/temp2);
}
float subtract(fraction& a,fraction& b)
{
	float temp1=a.numerator*b.denominator-b.numerator*a.numerator;
	float temp2=a.denominator*b.denominator;
	return (temp1/temp2);
}
float multiply(fraction& a,fraction& b)
{
	float temp1=a.numerator*b.numerator;
	float temp2=a.denominator*b.denominator;
	return (temp1/temp2);
}
fraction inc(fraction& a)
{
	fraction t;
	t.numerator=a.numerator+1;
	t.denominator=a.denominator+1;
	return t;
}
void main()
{
	float addition,sub,mul,inc;
	fraction f1(2,2),f2(2,2),f3;
	f1.print();
	f2.print();
	addition=add(f1,f2);
	cout<<"Add  :"<<addition<<endl;
	sub=subtract(f1,f2);
	cout<<"Subtraction  :"<<sub<<endl;
	mul=multiply(f1,f2);
	cout<<"Multiplication  :"<<mul<<endl;
	f3=inc(f1);
	f3.print();
}