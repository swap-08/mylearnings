/*************************<File Header>*************************/
/*!
@file: assignment2.c
@brief Abstract: Use of Standard Library Function

Description: Write a program to create a list of different
container names using list container. Use for_each to display 
all the values in the list.
Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/
#include<iostream>
#include<map>
using namespace std;
class student
{
	private: int stud_id,age;
	public: student()
			{
				stud_id=0;
				age=0;
			}

			void get_data()
			{
				cout<<"\nEnter student ID"<<endl;
				cin>>stud_id;
				cout<<"Enter student age"<<endl;
				cin>>age;
			}

			void put_data()
			{
				cout<<"\nStudent ID:\t"<<stud_id<<endl;
				cout<<"Student Age:\t"<<age<<endl;
			}
};

int main()
{
	student s1,s2,s3,s4;

	map<char *,class student> stud;

	stud["Swapnil"]=s1;
	stud["Shailesh"]=s2;
	stud["Aditya"]=s3;
	stud["Atharva"]=s4;

	map<char *,class student>::iterator i;
	for(i=stud.begin();i!=stud.end();i++)
	{
		cout<<(*i).first<<"\t";		//string
		(*i).second.get_data();		//object of class
	}

	for(i=stud.begin();i!=stud.end();i++)
	{
		cout<<(*i).first<<"\t";
		(*i).second.put_data();
	}
}