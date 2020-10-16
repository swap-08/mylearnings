/*************************<File Header>*************************/
/*!
@file: assignment3.c
@brief Abstract: Use of Standard Library Function

Description: 3.	Write a program to create a list of different
container names using list container. Use for_each to display 
all the values in the list.
Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/

#include <list>
#include <iostream>
#include<string>
using namespace std;

inline int main()
{   
 	list<char *> a;
//	list<string> a;   both can be use

	a.push_back("Swapnil");		// put new element after all the others
	a.push_back("Shailesh");	// put new element after all the others
	a.push_back("Aditya");		// put new element after all the others
	a.push_back("Atharva");		// put new element after all the others
	a.push_back("Ayush");		// put new element after all the others

	a.push_front("Kadam");		// put new element after all the others
	a.push_front("Mandavkar");	// put new element after all the others
	a.push_front("Jamdade");		// put new element after all the others
	a.push_front("Jamdade");		// put new element after all the others
	a.push_front("Gore");		// put new element after all the others

	list<char *>::iterator i;			//smart pointer
//	list<string>::iterator i;			//smart pointer
 
   for(i=a.begin(); i!= a.end(); ++i) 
   {
		 cout << *i << " ";
   }
	cout<<endl;

 	cin.get();
	return 0;
}
