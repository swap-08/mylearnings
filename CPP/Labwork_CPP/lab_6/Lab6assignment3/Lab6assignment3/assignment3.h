#include<iostream>
using namespace std;
#define HALF 0.5

class Shape
{
protected: float x;
		   float y;

public: void getData(float a,float b);
		virtual void displayArea()=0;
};

//member function
void Shape::getData(float a, float b)
{
	x=a;
	y=b;
}

//member function
void Shape::displayArea()
{
	cout<<"Virtual class"<<endl;
}



/****************************Derived class***************************/


class Rectangle:public Shape
{
public: void displayArea();

};

//member function
void Rectangle::displayArea()
{
	float area=x*y;
	cout<<"Area of Rectangle :"<<area<<endl;
}


/****************************Derived class***************************/
class Triangle:public Shape
{
public: void displayArea();

};

//member function
void Triangle::displayArea()
{
	float area=HALF*x*y;
	cout<<"Area of triangle :"<<area<<endl;
}