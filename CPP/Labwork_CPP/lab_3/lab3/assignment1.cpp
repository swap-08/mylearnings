/*************************<File Header>*************************/
/*!
@file: assignment1.cpp
@brief Abstract: Sample code
Author: Swapnil Kadam
Date:29/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
class Student
{
public:
	int iRoll;
	char cName[10];
	float fPercentage;
public:
	void setStudent(int isetRoll,char csetName[],float fsetPercentage)
	{
		if(fsetPercentage>60)
		{
			cout<<"\nStudent Name"<<endl<<csetName<<endl;
			cout<<"\nStudent Roll number"<<endl<<isetRoll<<endl;
			cout<<"\nStudent Percentage"<<endl<<fsetPercentage<<endl;
		}
	}
	void getStudent(void)
	{
		cout<<"Student Name"<<endl;
		cin>>cName;
		cout<<"Student Roll number"<<endl;
		cin>>iRoll;
		cout<<"Student Percentage"<<endl;
		cin>>fPercentage;
	}
};
void main()
{
	Student stud[5];
	char cStudName[10];
	int iStudRoll;
	float fStudPercentage;
		//accepting 10 student record
	for(int iCounter=0;iCounter<4;iCounter++)
	{
		stud[iCounter].getStudent();
	}
		//set record
	cout<<"\nThe student scoring First class are"<<endl;
	for(int iCounter=0;iCounter<4;iCounter++)
	{		
		stud[iCounter].setStudent(stud[iCounter].iRoll,stud[iCounter].cName,stud[iCounter].fPercentage);
	}
}