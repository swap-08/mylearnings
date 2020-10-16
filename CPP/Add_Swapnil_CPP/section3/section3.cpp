/*************************<File Header>*************************/
/*!
@file: section3.cpp
@brief Abstract: Write a template function that returns the
average of all the elements of an array
a.That argumens to the function should be the array name and array 
size of thearray(type)
b.In main(),exercise the function with arrays of type int,long,
double and char
Author: Swapnil Kadam
Date:05/12/2013
*/
/*****************************************************************/

#include"section3.h"

/*************************<Function Header>*************************/
/*!
@fn: void Array<T>::get_array(T *array1,int size)
@brief ABSTRACT:

Description: TAKING INPUT FROM USER
@param:  TWO PARAMETERS ARRAY AND SIZE OF ARRAY
@return :  NO RETURN VALUE
@remarks :NONE
@warning :NONE
@see :NONE
*/
/*****************************************************************/

template<class T>
T *arr Array<T>::get_array(T *array1,int size)
{
	array1=new T[size];
	for(int i=0;i<size;i++)
	{
		cin>>array1[i];
	}
	return array1;
}



/*************************<Function Header>*************************/
/*!
@fn: void Array<T>::display_array(T *array1,int size)
@brief ABSTRACT:

Description: DISPLAYING ARRAY
@param:  TWO PARAMETERS ARRAY AND SIZE OF ARRAY
@return :  NO RETURN VALUE
@remarks :NONE
@warning :NONE
@see :NONE
*/
/*****************************************************************/
template<class T>
T *arr Array<T>::display_array(T *array1,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<array1[i]<<endl;
	}
	return array1;
}


/*************************<Function Header>*************************/
/*!
@fn: void Array<T>::calculate_average(T *array1,int size)
@brief ABSTRACT:

Description: CALCULATING AVERAGE
@param:  TWO PARAMETERS ARRAY AND SIZE OF ARRAY
@return :  NO RETURN VALUE
@remarks :NONE
@warning :NONE
@see :NONE
*/
/*****************************************************************/
template<class T>

void Array<T>::calculate_average(T *array1,int size)
{
	T sum=0;
	T average;
	for(int i=0;i<size;i++)
	{
		sum=sum+array1[i];
	}
	average=sum/size;
	cout<<"Average of all array elements are"<<endl<<average<<endl;
}
	
//MAIN
void main()
{
	int size;
	cout<<"Enter array size :"<<endl;
	cin>>size;
	Array <int>i;		//INTEGER OBJECT CREATION
	int a[MAX];
	int t;
	t=i.get_array(a,size);		//CALLING  FUNCTION

	t=i.display_array(t,size);
		i.calculate_average(t,size);

/*
	Array <float>f;		//FLOATOBJECT CREATION
	float b[MAX];
	f.get_array(b,size);	//CALLING  FUNCTION
	f.calculate_average(b,size);
	f.display_array(b,size);
	

	Array <long>l;		//LONG OBJECT CREATION
	long c[MAX];
	l.get_array(c,size);	//CALLING  FUNCTION
	l.calculate_average(c,size);
	l.display_array(c,size);
	

	Array <char>ch;		//CHARACTER OBJECT CREATION
	char d[MAX];
	ch.get_array(d,size);	//CALLING  FUNCTION
	ch.calculate_average(d,size);
	ch.display_array(d,size);*/
}