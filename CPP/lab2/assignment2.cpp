/*************************<File Header>*************************/
/*!
@file: assignment2.cpp
@brief Abstract: Write a program with function repchar() which 
accepts a given character and a number and print character as 
many times
Author: Swapnil Kadam
Date:29/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
void repchar(char character,int a=5);
void main()
{
	char character;
	int number;
	cout<<"Enter any character"<<endl;
	cin>>character;
	cout<<"Enter any number"<<endl;
	cin>>number;
	repchar(character);
}
inline void repchar(char character,int a)
{
	for(int i=0;i<a;i++)
	{
		cout<<character<<endl;
	}
}