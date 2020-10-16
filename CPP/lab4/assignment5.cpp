/*************************<File Header>*************************/
/*!
@file: assignment5.cpp
@brief Abstract: Write a friend function to exchange data of two 
class
Author: Swapnil Kadam
Date:3/12/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
class two;
class one
{
	private:
		int data;
	public:
		one()
		{
			data=0;
		}
		one(int a)
		{
			data=a;
		}
		void display();
		friend void swap(one& num1,two& num2);
};
void one::display()
{
	cout<<"Number 1:"<<data<<endl;
}
class two
{
	private:
		int num;
	public:
		two()
		{
			num=0;
		}
		two(int a)
		{
			num=a;
		}
		void display();
		friend void swap(one& num1,two& num2);
};
void two::display()
{
	cout<<"Number 2:"<<num<<endl;
}
void swap(one& num1,two& num2)
{
	int temp;
	temp=num1.data;
	num1.data=num2.num;
	num2.num=temp;
}

void main()
{
	one obj1(2);
	two obj2(3);
	swap(obj1,obj2);
	obj1.display();
	obj2.display();
}