#include<iostream>
using namespace std;
class MyArray
{
	private: int *a, cs, size;
				MyArray()
				{
					a=new int [5];
					cs=0;
					size=5;
				}
	public: 
			    MyArray(int s, int v=0);
				MyArray(MyArray &t);
				void putMyArray();
				~MyArray()
				{
					delete []a;
				}
};
MyArray::MyArray(int s, int v)
{
		a=new int [s];
		size=s;
		for(int i=0;i<s;i++)
			a[i]=v;
		if(v==0)
			cs=0;
		else
			 cs=size;
}
MyArray::MyArray(MyArray &t)
{
	a=new int[t.size];
	for(int i=0;i<t.cs;i++)
		a[i]=t.a[i];
	cs=t.cs;
	size=t.size;
}
void MyArray::putMyArray()
{
	if(cs==0)
		cout<<"Array is empty"<<endl;
	else
		  for(int i=0;i<cs;i++)
				cout<<a[i]<<endl;
}
void main()
{
	MyArray t1(5,8), t2, t3(t1);
	t1.putMyArray();
	//t2.putMyArray();
	t3.putMyArray();
}