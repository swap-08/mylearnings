#include<iostream>
using namespace std;

double divide (long dividend, long divisor)
{
        if ( divisor  ==  0L )
                throw  "Division by zero " ;
        return (double) dividend / divisor ;
}

void main( )
{
       cout << "Enter a dividend and a divisor : " ;
       long dividend, divisor ;
       while( ! (cin >> dividend >> divisor) .eof( )) 
       {	
         try 
         {
                 cout << dividend << " / " << divisor <<"="<<divide( dividend, divisor);
         }
         catch ( const char* message) 
         {
				cerr << message << endl ;
        }
          cout << "Next dividend and divisor : " ;
       }
}