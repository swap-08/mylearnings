#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

// define how the items are to be tested for equality
struct ltstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};

int main()
{
  const int N = 7;
  const char* a[N] = {"sun", "mon", "tue", 
                      "wed", "thur", "fri","sat"};
  const char* b[N] = {"one", "two", "three",
	  "four", "five", "six","seven"};

  set<const char*, ltstr> A(a, a + N);
  set<const char*, ltstr> B(b, b + N);
  set<const char*, ltstr> C;

  cout << "Set A: ";
  copy(A.begin(), A.end(), ostream_iterator<const char*>(cout, " "));
  cout << endl;
  cout << "Set B: ";
  copy(B.begin(), B.end(), ostream_iterator<const char*>(cout, " "));   
  cout << endl;

  cout << "Union: ";
  set_union(A.begin(), A.end(), B.begin(), B.end(),
            ostream_iterator<const char*>(cout, " "),
            ltstr());   
  cout << endl;
  exit(0);
}
