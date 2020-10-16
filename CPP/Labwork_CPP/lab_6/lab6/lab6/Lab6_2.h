#include<iostream>
using namespace std;
class Base
{
public: void display()
		{
			cout<<"\nDisplay of the Base called\n";
		}
		void show()
		{
			cout<<"\nShow of the Base called\n";
		}
};


class Derived:public Base
{
public: void display()
		{
			cout<<"\nDisplay of the Derived called\n";
		}
		void show()
		{
			cout<<"\nShow of the Derived called\n";
		}
};