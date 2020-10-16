/*************************<File Header>*************************/
/*!
@file: assignment1.cpp
@brief Abstract: Use of Standard Library Function

Description: 1.	Create a stack of complex numbers that have integer
values. Push three different values in the stack. Retrieve each 
value and check if the stack is empty after all the values from 
the stack are removed. Also check the size of the stack before 
and after the values are removed.

Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/

#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int number;
	stack<int> complex;
	cout<<"Enter three elements"<<endl;
	//push elements
	for(int i=0;i<3;i++)
	{
		cin>>number;
		complex.push(number);
	}
	
	while(complex.size()!=0)
	{
		int temp=complex.top();
		cout<<"Top element is :"<<temp;
		complex.pop();
		cout<<"Popped.."<<endl;
		cout<<"Size of stack :"<<complex.size()<<endl;
	}
}