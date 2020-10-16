#include<iostream>
using namespace std;
class Base
{
	public:			Base()
					{
						cout<<"Base class Constructor"<<endl;
				    }
					~Base()
					{
						cout<<"Base class Destructor"<<endl;
				    }
					virtual void display()
					{
						cout<<"Base Class"<<endl;
				     }
};
class Derived: public Base
{
	public:			Derived()
					{
						cout<<"Derived class Constructor"<<endl;
				    }
					~Derived()
					{
						cout<<"Derived class Destructor"<<endl;
				    }
					void display()
					{
						cout<<"Derived Class"<<endl;
				     }
};
void main()
{
	Base *bptr;
	Derived d;
	//d.display();
	bptr=&d;
	//bptr=new Derived;
	bptr->display();
	//delete bptr;
}

