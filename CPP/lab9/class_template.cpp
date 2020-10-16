/*************************<File Header>*************************/
/*!
@file: class_template.cpp
@brief Abstract: Write a program to add two integers or float 
numbers using template class
Author: Swapnil Kadam
Date:05/12/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;


	//template class
template <class T>
class sample
{
private: //template variables declaration
		 T v,v1,v2;
public: void getdata();
		void sum();
};


	//member function
template<class T>
void sample<T>::getdata()
{
	cin>>v1>>v2;
}


	//member function
template<class T>
void sample<T>::sum()
{
	T v;
	v=v1+v2;
	cout<<"Sum =  "<<v<<endl;
}


void main()
{
	sample<int> obj1;
	sample<float> obj2;
	
		///integer object
	cout<<"Enter two integers:"<<endl;
	obj1.getdata();
	obj1.sum();

		//float object
	cout<<"Enter two floats:"<<endl;
	obj2.getdata();
	obj2.sum();
}