#include<iostream>
#include<string>
using namespace std;

const char *max(const char *x, const char *y) 
{
	return (strcmp(x,y)>0?x:y);
}

template <class T>
const T& max(const T& x, const T& y) 
{
	return (x > y) ? x : y ;
}
void main( ) {
	cout << max(1, 2) << endl ;
	cout << max(4L, 3L) << endl ;
	cout << max(5.62, 3.48) << endl ;
	cout << max("Aaa", "abb") << endl ;
	cout << max(5, 6) << endl ;
}
