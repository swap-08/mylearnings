/*************************<File Header>*************************/
/*!
@file: assignment1.cpp
@brief Abstract: Write a program which will have two inline 
functions sqr() and cube().These function will return square
and cube value of given input number
Author: Swapnil Kadam
Date:29/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
int sqr(int);
int cube(int=2);
void main()
{
	int number;
	cout<<"Enter any number "<<endl;
	cin>>number;
	cout<<"Square : "<<sqr(number)<<endl;

	cout<<"Cube : "<<cube(number)<<endl;
}
inline int sqr(int a)
{
	return a*a;
}
inline int cube(int a)
{
	return a*a*a;
}