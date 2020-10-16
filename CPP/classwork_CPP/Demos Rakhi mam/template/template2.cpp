#include<iostream.h>
template <class T>
class test 
{
	T number ;
public:	test( ) : number(0) { }	
	test( T n) : number(n)  { }	
	test(const test<T> &t):number( t.number ) {} // Copy constructor
	~test( )	{ }			
	test<T>& operator = ( const test<T>& t )  
	{
		number = t.number ;
		return  *this ;
	}
	friend ostream& operator << (ostream& stream, const test<T> &t )
	{
		return stream << t.number ;
	}
} ;
void main( )
{
	test <int>  t1(10) ;
	cout << t1  << endl ;
	test <long>  t2 (123456789L) ;
	cout << t2  << endl ;
}

