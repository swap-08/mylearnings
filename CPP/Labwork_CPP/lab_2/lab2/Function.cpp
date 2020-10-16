/*************************<File Header>*************************/
/*!
@file: Function.cpp
@brief Abstract: Write a program to find out maximum of two 
integers and two characters
Author: Swapnil Kadam
Date:29/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
int max(int,int=10);
char max(char,char);
void main()
{
	int a=21,b=5;
	cout<<"Maximum of "<<a<<" and "<<b<<" is "<<max(a,b);
	cout<<"\n";
	int c=5;
	cout<<"Maximum of "<<c<<" and "<<10<<" is "<<max(c);
	cout<<"\n";
	char ch1='a',ch2='z';
	cout<<"Maximum of "<<ch1<<" and "<<ch2<<" is "<<max(ch1,ch2)<<endl;
}
inline int max(int a,int b)
{
	int result;
	result=(a>b)?a:b;
	return (result);
}
inline char max(char ch1,char ch2)
{
	char result;
	result=(ch1>ch2)?ch1:ch2;
	return(result);
}