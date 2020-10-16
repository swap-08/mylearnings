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
	char ch;
	
	//check whether present or not

	if(!inf.good())
	{
		cout<<"Unable to open a file"<<endl;
		return 1;
	}
	//file present
	else
	{
		inf.seekg(0,ios::end);
		int length=inf.tellg();

		//cout<<length;

		for(int i=1;i<=length;i++)
		{
			inf.seekg(-i,ios::end);
			ch=inf.get();
			cout<<ch;
		}

	}
	inf.close();

	return 0;
}