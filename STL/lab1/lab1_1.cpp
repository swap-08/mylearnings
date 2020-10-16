/*************************<File Header>*************************/
/*!
@file: lab1_1.c
@brief Abstract: Use of Standard Library Function

Description:	Create a Console Based Project in Visual Studio 6.0.
Create a new C++ source file.  Write the following code in 
the source file.
Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/
#include <vector> // needed for vector 
#include <algorithm> // needed for reverse 
#include <iostream>
using namespace std; 
void main() { 
   vector<int> v(3); // Declare a vector of 3 ints 
   v[0] = 5; 
   v[1] = 4; 
   v[2] = v[0] + v[1]; 
   cout<<"Before reversing values of vector:";
   for(int i=0;i<v.size();i++)
   {
	   cout<<v[i]<<",";
   }
   cout<<endl;
   reverse(v.begin(), v.end());

  // reverse( v.end(),v.begin()); reutime eror iterator

   cout<<"After reversing values of vector:";
   for(int j=0;j<v.size();j++)
   {
	   cout<<v[j]<<",";
   }
}
