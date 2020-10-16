/*************************<File Header>*************************/
/*!
@file: Lab8_1.cpp
@brief Abstract: Write a program to handle exceptional situation
of accessing memory locations of an array beyond its limit

Author: Swapnil Kadam
Date:06/12/2013
*/
/*****************************************************************/

#include<iostream>
#define SIZE 10
using namespace std;

int main()
{

	int marks[SIZE]={23,43,45,53,32,56,35,63,57,88};

	try											//try for exception
	{
		for(int index=0;index<=100;index++)
		{
			if(index>SIZE-1)
				throw "Out of Range";			//throw exception which is to be catch
			cout<<marks[index]<<endl;
		}
	}

	catch(char *str)							//exception catch by throw
	{
		cout<<"Exception : "<<str<<endl;
	}

	return 0;
}