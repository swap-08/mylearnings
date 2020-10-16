/***********************************file header**************************************
@file: assignment2.cpp
@breif Abstract: File Handling
Description: Copy a text file into another by toggling the case of each letter from
the source file
Author:Swapnil Kadam
Date:04/12/2013
****************************************************************************************/
#include<iostream>
#include<fstream>
using namespace std;
#define MAX 20
int main()
{
	char str[MAX],temp[MAX];
	
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
		inf>>str;				//reading content of file

		cout<<"File content is :"<<str<<endl;

	}
	inf.close();			//closing a read file


	/*****************************************************************************/


	ofstream outf("file2.txt");			//file object

	for(int i=0;i<strlen(str);i++)
	{
		temp[i]=toupper(str[i]);
	}
	
	for(int i=0;i<strlen(str);i++)
	{
		cout<<temp[i];
	}
	
	for(int i=0;i<strlen(str);i++)
	{
		outf<<temp[i];
	}

	outf.close();			//closing a read file


}