#include"assignment4.h"

void main()
{
	Shape *s;			//base class object pointer
	Rectangle r;		//derived class object
	s=&r;				//assigning address of rectangle object to object pointer

	int side1,side2;

	cout<<"Enter first side :"<<endl;
	cin>>side1;

	cout<<"Enter second side :"<<endl;
	cin>>side2;
	s->getData(side1,side2);
	s->displayArea();

	Triangle t;			//derived class object
	s=&t;				//assigning address of triangle object to object pointer

	s->getData(side1,side2);
	s->displayArea();

	Circle c;			//derived class object
	s=&c;				//assigning address of triangle object to object pointer

	float radius;
	cout<<"Enter radius of circle"<<endl;
	cin>>radius;

	s->getData(radius);
	s->displayArea();
}