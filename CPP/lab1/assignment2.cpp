/*************************<File Header>*************************/
/*!
@file: assignment2.cpp
@brief Abstract: Write a program to get array of values and perform
four arithmetic calculations based on enumerated values like PLUS
MINUS MULTIPLY and DIVIDE
Author: Swapnil Kadam
Date:29/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
//int operators=4;
void main()
{
	int *a1,*a2,*total,size;
	cout<<"Enter size of array"<<endl;
	cin>>size;
	a1=new int[size];
	//a2=a1;  not works
	a2=new int[size];
	//total=a1;
	cout<<"Enter elements of array 1"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>a1[i];
	}

	cout<<"Enter elements of array 2"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>a2[i];
	}
	int input;
	cout<<"Enter choice 1.PLUS 2.MINUS 3.MULTIPLY 4.DIVIDE"<<endl;
	cin>>input;
	input--;

	enum arith{PLUS,MINUS,MULTIPLY,DIVIDE};
	if(input==0)
	{
	cout<<"Addition:"<<endl;
		for(int i=0;i<size;i++)
		{
			cout<<a1[i]+a2[i]<<endl;
		}
	}
	else if(input==1)
	{
	cout<<"Subtraction:"<<endl;
		for(int i=0;i<size;i++)
		{
			cout<<a1[i]-a2[i]<<endl;
		}
	}
	else if(input==2)
	{
	cout<<"Multiplication:"<<endl;
		for(int i=0;i<size;i++)
		{
			cout<<a1[i]*a2[i]<<endl;
		}
	}
	else if(input==0)
	{
	cout<<"Division:"<<endl;
		for(int i=0;i<size;i++)
		{
			cout<<a1[i]/a2[i]<<endl;
		}
	}
	else
		cout<<"Invalid choice";

}