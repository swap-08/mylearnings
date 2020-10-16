/*************************<File Header>*************************/
/*!
@file: assignment1.cpp
@brief Abstract: Write a program to handle exceptional situation
of accessing memory locations of an array beyond its limit
Author: Swapnil Kadam
Date:06/12/2013
*/
/*****************************************************************/

#include<iostream>
using namespace std;
void global_function(int a);			//global function
int main()
{
	int num;
	cout<<"Enter number to be lookup"<<endl;
	cin>>num;
	
	global_function(num);				//calling global function
}


//function definition
void global_function(int a)
{
	a--;
	enum number{One,Two,Three,Four,Five};
		try													//try for exception
		{
			if(a==One)
				cout<<"1";

			else if(a==Two)
				cout<<"2";

			else if(a==Three)
				cout<<"3";

			else if(a==Four)
				cout<<"4";

			else if(a==Five)
				cout<<"5";

			else
				throw "Invalid choice";					//throw exception to be catch
		}
		catch(char *str)						
		{
			cout<<"Exception is: "<<str;				//action taken for exception
		}
}

