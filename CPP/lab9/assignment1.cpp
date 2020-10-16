/*************************<File Header>*************************/
/*!
@file: assignment1.cpp
@brief Abstract: Write a program to swap two integers or float 
numbers using template function
Author: Swapnil Kadam
Date:05/12/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;

//template creation
template<class T>

	//call by address
void swapnumber(T &a,T &b)
{
	T temp;			//template variable creation
	temp=a;
	a=b;
	b=temp;
}


//main function
int main()
{
	int i=5,j=6;
	float l=10.2,m=5.2;
	//char c='r',d='j';  Error unable to swap character

	//calling by float value
	cout<<"Before swappnig :"<<endl<<l<<endl<<m<<endl;	
	swapnumber<float>(l,m);
	cout<<"After swappnig :"<<endl<<l<<endl<<m<<endl;

	//calling by integer value
	cout<<"Before swappnig :"<<endl<<i<<endl<<j<<endl;	
	swapnumber<int>(i,j);
	cout<<"After swappnig :"<<endl<<i<<endl<<j<<endl;
	return 0;
}