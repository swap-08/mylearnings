/*************************<File Header>*************************/
/*!
@file: assignment2.c
@brief Abstract: Use of Standard Library Function

Description: For the above vector, find the sum of numbers stored
in vector, and validate if the sum=227
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
	 
   cout<<"Values of vector:";
   for(int i=0;i<v.size();i++)
   {
	   cout<<v[i]<<",";
   }
   cout<<endl;

   int sum=0;	//initialising sum=0

   for(int j=0;j<v.size();j++) //calculating sum of all vector elements
   {
	   sum=sum+v[j];
   }

   cout<<"After adding all the values of vector:"<<endl<<"Sum is :"<<sum<<endl;
}
