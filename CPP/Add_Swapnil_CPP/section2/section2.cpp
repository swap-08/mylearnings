/*************************<File Header>*************************/
/*!
@file: section2.cpp
@brief Abstract: Write a program that returns the size in bytes 
of a program file entered on the command lins
Author: Swapnil Kadam
Date:13/12/2013
*/
/*****************************************************************/
#include<iostream>
//#include<fstream>
using namespace std;

//MAIN
void main(int argc,char *argv[])
{
	//OPEINING FILE IN READ MODE

	cout<<argv[1];

	/*ifstream inf(argv[1]);			//CREATION OF IFSTREAM OBJECT
	
	//CHECK WHETHER FILE PRESENT OR NOT

	if(!inf.good())
	{
		cout<<"Unable to open a file"<<endl;
		exit(1);	//EXIT WITH ERROR
	}

	//file present
	else
	{
	
		inf.seekg(0,ios::end);			//MOVE THE POINTER TO THE END POSITION OF FILE USING SEEK

		int length=inf.tellg();			//CALCULATE THE LENGTH FROM START USINF TELL

		cout<<"Length of a file in Bytes is:\t"<<length<<endl;	//DISPLAY LENGTH
	}*/
}