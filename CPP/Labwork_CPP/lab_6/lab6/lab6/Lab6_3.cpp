/*************************<File Header>****************************/
/*!
@file: Lab6_2.cpp
@brief Abstract: Inheritance with virtual function
Author: Swapnil Kadam
Date:04/12/2013
*/
/*****************************************************************/
#include"Lab6_2.h"
int main()
{
	Base B;
	Derived D;
	Base *bptr;
	
	cout<<"\n bptr points to the Base\n";
	
	bptr=&B;
	bptr->display();	//calls base version
	bptr->show();		//calls base version
	
	cout<<"\n bptr points to the Derived\n";
	
	bptr=&D;
	bptr->display();	//calls derived version
	bptr->show();		//calls derived version
	
	return 0;
}