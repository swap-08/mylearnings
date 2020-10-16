#include<iostream.h>
template <class T1, class T2>
class test 
{
		T1 a;
		T2 b;
public:
		test( )
		{ 
			a=b=0;		
		}	
		test( T1 x, T2 y)
		{ 
			a=x;
			b=y;
		}	
		test(const test<T1,T2> &t)
		{
			a=t.a;
			b=t.b;
		}
		~test( )	{ }	
		friend ostream& operator << (ostream& stream, const test<T1,T2>&  t )
		{
			cout<< "Value 1:"<<t.a<<endl ;
			cout<< "Value 2:"<<t.b<<endl ;
			return stream;
		}

		void setdata(T1 x,T2 y);
};
template <class T1, class T2>
void test<T1,T2>::setdata(T1 x,T2 y)
{
	a=x;
	b=y;
}
void main( )
{
	test <int,float> t1(10,32.56f) ;
	cout << t1  << endl ;
}

