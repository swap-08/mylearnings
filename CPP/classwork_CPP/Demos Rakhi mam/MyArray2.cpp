#include<iostream>
using namespace std;
class MyArray
{
	private: int *a, cs, size;
				
	public: 
				MyArray()
				{
					a=new int [5];
					cs=0;
					size=5;
				}
			    MyArray(int s, int v=0);
				MyArray(MyArray &t);
				void putMyArray();
				MyArray operator -();
				MyArray operator +(MyArray &y);
				MyArray& operator =(MyArray &y);
				~MyArray()
				{
					delete []a;
				}
};
MyArray MyArray::operator -()
{
	MyArray t(size);
	for(int i=0;i<cs;i++)
		t.a[i]=-a[i];
	t.cs=cs;
	t.size=size;
	return t;
}
MyArray MyArray::operator +(MyArray &y)
{
	MyArray t(size+y.size);
	int i,j;
	for(i=0;i<cs;i++)
		t.a[i]=a[i];
	for(j=0;j<y.cs;j++)
		t.a[i+j]=y.a[j];
	t.size=size+y.size;
	t.cs=cs+y.cs;
	return t;
}

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
MyArray& MyArray::operator =(MyArray &y)
{
	delete a;
	a=new int[y.size];
	for(int i=0;i<y.cs;i++)
		a[i]=y.a[i];
	cs=y.cs;
	size=y.size;
	return (*this);
}
void main()
{
	MyArray t1(5,8), t2,t3;
	t2=-t1;
	t3=t1+t2;
	t3.putMyArray();
}
