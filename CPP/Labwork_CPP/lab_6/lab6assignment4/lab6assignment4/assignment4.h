#include<iostream>
//#include<math>
using namespace std;
#define HALF 0.5
#define PI 3.1412
class Shape
{
protected: float x;
		   float y;

public: void getData(float a,float b);
		void getData(float a);
		virtual void displayArea()=0;
};


void Shape::getData(float a, float b)
{
	x=a;
	y=b;
}
void Shape::getData(float a)
{
	x=a;
}
void Shape::displayArea()
{
	cout<<"Virtual class"<<endl;
}



/****************************Derived class***************************/


class Rectangle:public Shape
{
public: void displayArea();

};
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
void Triangle::displayArea()
{
	float area=HALF*x*y;
	cout<<"Area of triangle :"<<area<<endl;
}


/****************************Derived class***************************/
class Circle:public Shape
{
public: void displayArea();

};
void Circle::displayArea()
{
	float sqrt=x*x;
	float area=PI*sqrt;
	cout<<"Area of circle :"<<area<<endl;
}