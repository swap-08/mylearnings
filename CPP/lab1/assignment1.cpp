/*************************<File Header>*************************/
/*!
@file: enumerated.c
@brief Abstract: Write a program that declare a string pointer 
initialized to some value,and then proceed to put the characters 
in reverse order.
Author: Swapnil Kadam
Date:29/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
void main()
{
	char *str,string[20];
	cout<<"Enter string"<<endl;
	cin>>string;
	//coping address of zeroth location of string array
	str=string;
	cout<<"String in reverse order"<<endl;
	for(int i=strlen(string)-1;i>=0;i--)
	{
		cout<<str[i];
	}
}