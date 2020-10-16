#include <iostream>
#include <set>
#include <vector>
using namespace std;
template <class T>
void print(T &c)
{
	for(typename T::iterator i=c.begin(); i!=c.end();i++)
	{
		std::cout<< *i <<endl;
	}
}
void main()
{
	const int num_grades=11;
	const int grade[num_grades]= {2,5,3,8,9,9,6,3,5,9,10};
	set<int> unique(grade,grade+num_grades);
	multiset<int> all(grade,grade+num_grades);
	print(unique);
	print(all);
}