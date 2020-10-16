/*************************<File Header>*************************/
/*!
@file: lab2_1.cpp
@brief Abstract: Use of Standard Library Function

Description: Create a set and store values into the set.Display 
the values to show that they are stored in an ascending order.
Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/
#include <iostream>
#include <set>
using namespace std;

int main()
{
    /* type of the collection:
     * - no duplicates
     * - elements are integral values
     * - descending order
     */
    typedef set<int,greater<int>> IntSet;
	//set<int> coll1;        // empty set container

	IntSet coll1;

    // insert elements in random order
    coll1.insert(4);
    coll1.insert(3);
    coll1.insert(5);
    coll1.insert(1);
    coll1.insert(6);
    coll1.insert(2);
    coll1.insert(5);


	set<int,greater<int>>::iterator i;
	//set<int>::iterator i;

	for(i=coll1.begin();i!=coll1.end();i++)
	{
		cout<<*i;
	}

	cout<<"\nUsing copy"<<endl;

	copy(coll1.begin(), coll1.end(), ostream_iterator<const int>(cout, " "));
    cout << endl;

}
