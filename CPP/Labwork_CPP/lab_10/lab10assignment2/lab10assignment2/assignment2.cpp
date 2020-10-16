/***********************************file header**************************************
@file: assignment2.cpp
@breif Abstract: File Handling
Description: Write a program to display the contents of a test file in reverse order
Author:Swapnil Kadam
Date:04/12/2013
****************************************************************************************/

#include<iostream>
//#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
#define MAX 20
int main()
{
	//write operation

	ofstream outf("file1.txt");			//file object
	int counter=0;

	char str[MAX],temp[MAX];

	cout<<"Enter any string:"<<endl;
	cin>>str;

	outf<<str;					//writing in a file

	outf.close();				//closing a file


	/**********************************************************************************/
	//reading a file

	ifstream inf("file1.txt");			//file object
	
	//check whether present or not

	if(!inf.good())
	{
		cout<<"Unable to open a file"<<endl;
		return 1;
	}
	//file present
	else
	{
		char temp1[30];

		inf>>str;				//reading a file

		cout<<"File content is :"<<str<<endl;

		for(int i=strlen(str)-1;i>=0;i--)
		{
			temp[counter]=str[i];
			counter++;
		}

		for(int i=0;i<counter;i++)
		{
				cout<<temp[i];
		}
	}
	inf.close();

	/****************************************************************************************/

	//writing a file

	ofstream outf1("file2.txt");

	for(int i=0;i<counter;i++)
	{
		outf1<<temp[i];
	}
	outf1.close();

	return 0;
}