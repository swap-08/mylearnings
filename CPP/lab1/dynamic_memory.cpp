/*************************<File Header>*************************/
/*!
@file: dynamic_memory.c
@brief Abstract: Write a program to create an array dynamically
and display it
Author: Swapnil Kadam
Date:29/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
int main()
{
	char input[100];
	int i,n;
	long *l;
	cout<<"How many numbers do you want to type in ?";
	cin.getline(input,100);
	i=atoi(input);
	//cout<<"iii"<<i<<endl;
	l=new long[i];
	//cout<<"lll"<<*l<<endl;
	if(l==NULL)
		exit(1);
	for(n=0;n<i;n++)
	{
		cout<<"Enter number: ";
		cin.getline(input,100);
		l[n]=atoi(input);
	}
	cout<<"You have entered: ";
	for(n=0;n<i;n++)
		cout<<l[n];
	delete[]l;
	return 0;
}