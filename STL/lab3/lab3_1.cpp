/*************************<File Header>*************************/
/*!
@file: lab3_1.cpp
@brief Abstract: Use of Standard Library Function

Description: Create a Console Based Project in Visual Studio 6.0.
Create a new C++ source file.  Write the following code in the
source file.
Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/

#include <stack>
#include <iostream>
using namespace std;

int main() 
{
	  stack<int> mynums; //initialise stack template

	  /*PUSH TO STACK*/
	  mynums.push(55);
	  mynums.push(66);
	  mynums.push(77);

	  cout << "Top element is " <<  mynums.top()  <<endl;

	  /*POP FROM STACK*/
	  mynums.pop();
	  mynums.pop();
	  mynums.pop();
	  cout << "Number of elements is now " << mynums.size() <<endl;
}
