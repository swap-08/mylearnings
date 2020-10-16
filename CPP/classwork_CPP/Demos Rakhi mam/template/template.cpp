#include<iostream>
using namespace std;
template <class T>
 T max(T x,T y)
{
	return (x > y) ? x : y ;
}
void main( ) {
	cout << max(1, 2) << endl ;
	cout << max(4L, 3L) << endl ;
	cout << max(5.62, 3.48) << endl ;
	cout << max('A', 'a') << endl ;
	cout << max(5, 6) << endl ;
}
