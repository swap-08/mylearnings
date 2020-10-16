/*************************<File Header>*************************/
/*!
@file: assignment2.c
@brief Abstract: Use of Standard Library Function

Description: Given is a list of values: {23,42,12,45,22,56,64,55}.
Create a queue and push the first three elements from the above 
list.Display the current size. Pop these elements.
Now add next five elements and pop them to out.
Display the size of the queue

Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int number,temp;
	queue<int> q;

	//inserting 3 elements
	cout<<"Enter first 3 elements"<<endl;
	for(int i=0;i<3;i++)
	{
		cin>>number;
		q.push(number);
	}
	cout<<"Curretn size of queue:\t"<<q.size()<<endl;

	//removing 3 elements from front
	cout<<"Getting 3 elements from front"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"Element popped"<<endl;
		temp=q.front();
		q.pop();
		cout<<temp<<endl;
	}
	cout<<"Current size of queue:\t"<<q.size()<<endl;


	//inserting 5 elements
	cout<<"Enter 5 elements from front"<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>number;
		q.push(number);
	}

	//removing 5 elements from front
	cout<<"Getting 5 elements from front"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Element popped"<<endl;
		temp=q.front();
		q.pop();
		cout<<temp<<endl;
	}
	cout<<"Current size of queue:\t"<<q.size()<<endl;

	return 0;
}