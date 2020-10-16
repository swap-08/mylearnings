
#include<iostream>
using namespace std;
#include<string>
class String
{
	private: 
	
	public: void replace_all(string& s,const string& pattern,string& replace)
			{
				cout<<s<<endl<<pattern<<endl<<replace<<endl;
				s+=pattern;
				cout<<s;
				char c=s[2];
				cout<<c;

				string a;
				a.append(replace);
				cout<<a;
				
				int pos;
				pos=s.find(pattern,0);
				
				cout<<s;

				//s[pos].swap(replace);

				s.swap(replace);
				cout<<s;



			}
};
