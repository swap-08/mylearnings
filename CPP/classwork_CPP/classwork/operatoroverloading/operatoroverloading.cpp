#include<iostream>
using namespace std;
class MKS
{
	private: int m;
	            int cm;
	public:	   MKS()//Default Constructor
			   {
			       m=cm=0;
		       }
			   MKS(int x,int y)//Parameterized Constructor
				{
					m=x;
					cm=y;
				}
				void putMKS()
				{
					cout<<"Meters:"<<m<<endl;
					cout<<"Centimeters:"<<cm<<endl;
				}
				/*void operator -()
				{
					m=-m;
					cm=-cm;
				}*/
				MKS& operator -()
				{
					MKS t;
					t.m=-m;
					t.cm=-cm;
					return t;
				}
				MKS& operator --() //prefix
				{
					MKS t;
					--cm;
					if(cm>=100)
					{
						m=m+cm/100;
						cm=cm%100;
					}
					t.cm=cm;
					t.m=m;
					return t;
				}
				MKS& operator --(int) //postfix
				{
					MKS t;
					t.cm=cm;
					t.m=m;
					--cm;
					if(cm>=100)
					{
						m=m+cm/100;
						cm=cm%100;
					}
					return t;
				}
				MKS& operator +(MKS &x) 
				{
					MKS t;
					t.cm=cm+x.cm;
					t.m=m+x.m;
					if(t.cm>=100)
					{
						t.m=t.m+t.cm/100;
						t.cm=t.cm%100;
					}
					return t;
				}
				friend istream& operator>>(istream &in, MKS &t);
				friend ostream& operator<<(ostream &out, MKS &t);
};
istream& operator>>(istream &in, MKS &t)
{
	cout<<"Enter Meters:";
	cin>>t.m;
	cout<<"Enter Centimeters:";
	cin>>t.cm;
	return in;
}
ostream& operator<<(ostream &out, MKS &t)
{
	cout<<"Meters:"<<t.m<<endl;
	cout<<"Centimeters:"<<t.cm<<endl;
	return out;
}
void main()
{
	MKS x(5,99),y,z;
	//y=-x;
	y=--x;
	//y=x--;
	z=x+y;
	cout<<x<<y<<z;
}