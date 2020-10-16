/*************************<File Header>*************************/
/*!
@file: Function_template.cpp
@brief Abstract: Write a program to find minimumof two integers,
character and float numbers using function template
Author: Swapnil Kadam
Date:05/12/2013
*/
/*****************************************************************/

#include<iostream>
using namespace std;

//template creation
template<class T>

T GetMax(T a,T b)
{
	T result;
	result=(a>b)?a:b;
	return (result);
}


//main function
int main()
{
	int i=5,j=6;
	float l=10.2,m=5.2;
	char c='r',d='j';

	cout<<"GetMax<int>(5,6)         :"<<GetMax<int>(i,j)<<endl;
	cout<<"GetMax<float>(10.2,5.2)  :"<<GetMax<float>(l,m)<<endl;
	cout<<"GetMax<char>(r,j)        :"<<GetMax<char>(c,d)<<endl;
}