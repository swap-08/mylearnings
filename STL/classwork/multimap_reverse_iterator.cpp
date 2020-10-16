#include <iostream>
#include <map>
using namespace std;

int main ()
{
  multimap<char,int> mymultimap;
  multimap<char,int>::reverse_iterator rit;

  mymultimap.insert (pair<char,int>('x',10));
  mymultimap.insert (pair<char,int>('y',20));
  mymultimap.insert (pair<char,int>('y',150));
  mymultimap.insert (pair<char,int>('z',9));

  // show content:
  for ( rit=mymultimap.rbegin() ; rit != mymultimap.rend(); rit++ )
    cout << rit->first << " => " << rit->second << endl;

  return 0;
}
