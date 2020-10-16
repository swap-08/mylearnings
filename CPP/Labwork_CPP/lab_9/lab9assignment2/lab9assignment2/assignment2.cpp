/*************************<File Header>*************************/
/*!
@file: assignment2.cpp
@brief Abstract: Write a program to swap two integers or float 
numbers using template function
Author: Swapnil Kadam
Date:05/12/2013
*/
/*****************************************************************/

#include<iostream>
using namespace std;
#define MAX 5

//template creation
template<class T>
class sort_array
{

private: T *array1,*array2,*array3;			//template variable declaration

public: void get_array();					//member function declaration
		void display_array();
		void add_array();
		void sorted_array();
};


//inserting elements in array
template<class T>
void sort_array<T>::get_array()
{
	array1=new T[MAX];
	array2=new T[MAX];
	array3=new T[MAX];

	cout<<"Enter first array elements"<<endl;
	for(int i=0;i<MAX;i++)
	{
		cin>>array1[i];
	}
	
	cout<<"Enter second array elements"<<endl;
	for(int i=0;i<MAX;i++)
	{
		cin>>array2[i];
	}
}


//display all arrays
template<class T>
void sort_array<T>::display_array()
{
	
	cout<<"Array Elements are"<<endl;
	cout<<"Array 1"<<endl;
	
	for(int i=0;i<MAX;i++)
	{
		cout<<array1[i]<<endl;
	}
	
	cout<<"Array 2"<<endl;
	for(int i=0;i<MAX;i++)
	{
		cout<<array2[i]<<endl;
	}
	
	cout<<"Resultant array"<<endl;
	for(int i=0;i<MAX;i++)
	{
		cout<<array3[i]<<endl;
	}

}


//performing addition of array1 and array 2 elements
template<class T>
void sort_array<T>::add_array()
{
	for(int i=0;i<MAX;i++)
	{
		array3[i]=array1[i]+array2[i];
	}
}

//sorting resultant array
template<class T>
void sort_array<T>::sorted_array()
{
	T temp;
	for(int i=0;i<MAX-1;i++)
	{
		for(int j=0;j<MAX-1;j++)
		{
			if(array3[j]>array3[j+1])
			{
				temp=array3[j];
				array3[j]=array3[j+1];
				array3[j+1]=temp;
			}
		}
	}
}

void main()
{
	sort_array <float>s1;
	//sort_array <float>s2;
	s1.get_array();
	
	s1.add_array();
	cout<<"After adding array1 and array2"<<endl<<"************************************************"<<endl;
	s1.display_array();

	s1.sorted_array();
	cout<<"After sorting array3"<<endl<<"************************************************"<<endl;
	s1.display_array();
}
