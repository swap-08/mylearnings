/*************************<File Header>*************************/
/*!
@file: lab4_3.cpp
@brief Abstract: Use of Standard Library Function

Description: Create a Console Based Project in Visual Studio 6.0.
Create a new C++ source file.  Write the following code in the
source file.

Author: Swapnil Kadam
Date:11/12/2013
Change History: None
*/
/*****************************************************************/

#include <algorithm>   // for set_intersection, set_union
#include <iostream>    // for cout, endl
#include <set>         // for set


typedef std::multiset<int, std::less<int>, 
                      std::allocator<int> > set_type;

inline std::ostream& operator<< (std::ostream& out, 
                                 const set_type& s)
{
    typedef std::ostream_iterator<set_type::value_type, char,
        std::char_traits<char> > os_iter;

    std::copy (s.begin (), s.end (), os_iter (std::cout, " "));

    return out;
}


int main ()
{
    // Create a multiset of integers.
    set_type  si;

    for (set_type::value_type j = 0; j < 2; j++) {
        for (set_type::value_type i = 0; i < 10; ++i)
            // Insert values with a hint.
            si.insert (si.begin (), i);
    }

    // Print out the multiset.
    std::cout << si << std::endl;
    // Make another multiset and an empty multiset.
    set_type si2, result;
    for (set_type::value_type i = 0; i < 10; i++)
        si2.insert (i + 5);

    std::cout << si2 << std::endl;

    // Try a couple of set algorithms.
    std::set_union (si.begin (), si.end (), 
                    si2.begin (), si2.end (),
                    std::inserter (result, result.begin ()));

    std::cout << "Union:\n" << result << std::endl;

    result.erase (result.begin (), result.end ());

    std::set_intersection (si.begin (), si.end (), 
                       si2.begin (), si2.end (),
                       std::inserter(result, result.begin()));

    std::cout << "Intersection:\n" << result << std::endl;

    return 0;
}
