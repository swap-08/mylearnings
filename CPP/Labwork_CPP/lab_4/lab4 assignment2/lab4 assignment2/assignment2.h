#include<iostream>
using namespace std;
class complex
{
	private:
		float real,imag;
	public:
		complex()
		{
			real=0;
			imag=0;
		}
		complex(float x,float y);
		complex(complex &x);		//copy constructor
		float getReal();
		float getImag();
		void increment();
		void print();
		complex& complex::add(complex x,complex y);
};