/*************************<File Header>*************************/
/*!
@file: lab4_1.cpp
@brief Abstract: Use of Standard Library Function

Description: Create a Console Based Project in Visual Studio 6.0.
Create a new C++ source file.  Write the following code in the 
source file.

Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>  // For find
using namespace std; 
template <typename Container>
Container make(const char s[])
{
  return Container(&s[0], &s[strlen(s)]);
}

int main()
{
  cout << "Demo for find algorithm with a vector" << endl;

  vector<char> vector1 = 
    make< vector<char> >("C++ is a better C");

  // Search for the first occurrence of the letter e:
  vector<char>::iterator
    where = find(vector1.begin(), vector1.end(), 'e');

  assert (*where == 'e' && *(where + 1) == 't');
  cout << " --- Ok." << endl;
  return 0;
}
