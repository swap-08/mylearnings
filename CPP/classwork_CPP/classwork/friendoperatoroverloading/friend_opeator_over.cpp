#include<iostream>
using namespace std;
class MKS
{
	private: int m;
	            int cm;
	public: MKS()//Default Constructor
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
				friend MKS& operator -(MKS &x);
				friend MKS& operator ++(MKS &x);
				friend MKS& operator ++(MKS &x,int);
				//friend MKS& operator +(MKS &x,MKS &y);
				friend MKS& operator +(MKS &x,int a);
};
MKS& operator -(MKS &x)
{
		MKS t;
		t.m=-x.m;
		t.cm=-x.cm;
		return t;
}
MKS& operator ++(MKS &x) //prefix
{
		MKS t;
		++x.cm;
		if(x.cm>=100)
		{
			x.m=x.m+x.cm/100;
			x.cm=x.cm%100;
		}
		t.cm=x.cm;
		t.m=x.m;
		return t;
}
MKS& operator ++(MKS &x,int) //postfix
{
		MKS t;
		t.cm=x.cm;
		t.m=x.m;
		++x.cm;
		if(x.cm>=100)
		{
			x.m=x.m+x.cm/100;
			x.cm=x.cm%100;
		}
		return t;
}
/*
MKS& operator +(MKS &x,MKS &y) 
{
		MKS t;
		t.cm=x.cm+y.cm;
		t.m=x.m+y.m;
		if(t.cm>=100)
		{
				t.m=t.m+t.cm/100;
				t.cm=t.cm%100;
		}
		return t;
}*/

MKS& operator +(MKS &x,int a) 
{
		MKS t;
		t.cm=x.cm+a;
		t.m=x.m+a;
		if(t.cm>=100)
		{
				t.m=t.m+t.cm/100;
				t.cm=t.cm%100;
		}
		return t;
}

void main()
{
	MKS x(5,9),y(10,10),z;
	//y=-x;
	//y=++x;
	//y=x++;
	//z=y+x;
	z=x+10;
	//10+x
	//x.putMKS();
	//y.putMKS();
	z.putMKS();
}