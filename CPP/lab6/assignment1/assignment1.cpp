/***********************************file header**************************************
@file: assignment1.cpp
@breif Abstract:Inheritance
Description:This program contain bank account maintaing two kinds of account and displaying
			there details.
Author:Swapnil Kadam
Date:04/12/2013
****************************************************************************************/

#include "assignment1.h"

void main()
{
	Savings_Acc s("swapnil",101,1500,0.02);				//saving account object creation

	cout<<"**********************Saving Account****************************"<<endl;
	
	s.display();

	cout<<"***************Deposit Cash in Saving Account*******************"<<endl;
	s.deposit();

	cout<<"***************Withdraw Cash from Saving Account*******************"<<endl;
	s.withDraw();

	cout<<"***************Compute Interest of Saving Account*******************"<<endl;
	s.computeInterest();

	cout<<"*******************Details of Saving Account*******************"<<endl<<endl<<endl;
	s.display();
	
	cout<<"**********************Current Account****************************"<<endl;

	Current_Acc c("aditya",102,1500,1000);				//current account object creation
	c.display();

	cout<<"***************Deposit Cash in Current Account*******************"<<endl;
	c.deposit();

	cout<<"***************Withdraw Cash from Current Account*******************"<<endl;
	c.withDraw();

	cout<<"*******************Details of Current Account***********************"<<endl;
	c.display();
	
}
 
