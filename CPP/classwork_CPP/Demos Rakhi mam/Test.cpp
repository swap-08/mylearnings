#include<iostream>
using namespace std;
void main()
{
    try
	{
		throw "Error";
	}
	catch( char *s)
    {
         throw;
    }
}