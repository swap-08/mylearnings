/*************************<File Header>*************************/
/*!
@file: assignment1.c
@brief Abstract: Use of Standard Library Function

Description: Create an integer vector and put the following
values into it (34, 65, 22, 43, 12, 51). Sort these elements,
and then display the sorted elements.
Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/

#include <vector> // needed for vector 
#include <algorithm> // needed for reverse 
#include <iostream>
using namespace std; 
void main() 
{ 
	vector<int> v(6); // Declare a vector of 6 ints  
	v[0]=34;
	v[1]=65;
	v[2]=22;
	v[3]=43;
	v[4]=12;
	v[5]=51;
	 
   cout<<"Before sorting values of vector:";
   for(int i=0;i<v.size();i++)
   {
	   cout<<v[i]<<",";
   }
   cout<<endl;

   sort(v.begin(), v.end()); //sort algorithm

   cout<<"After sorting values of vector:";
   for(int j=0;j<v.size();j++)
   {
	   cout<<v[j]<<",";
   }
   cout<<endl;
}
