#include<iostream>
using namespace std;
class MyArray
{
private: int *a,size,cs;
			int co,flag;
public:	MyArray();
			MyArray(int,int);
			MyArray(MyArray &);
			void getArray();
			void setArray(int);
			void putArray();
			void addelement(int x);
			~MyArray()
			{
				 delete a;
			}

			MyArray& operator =(int x)
			{
				 int i;
				 if(flag==1)
				 {
					a[co]=x;
					flag=co=0;
				 }
				else
				{
						for(i=0;i<size;i++)
							a[i]=x;
						cs=size;
				}
				return (*this);
			}
			MyArray& operator[](int x)
			{
				 flag=1;
				 co=x;
				 return (*this);
		    }
		 
};

MyArray::MyArray()
{
	int i;
	a=new int[5];
	size=5;
	for(i=0;i<size;i++)
		a[i]=0;
	cs=0;
	flag=co=0;
}
MyArray::MyArray(int s,int v=0)
{
	a=new int[s];
	size=s;
	for(int i=0;i<size;i++)
		a[i]=v;
	if(v==0)
		cs=0;
	else
		cs=size;
	flag=co=0;
}
MyArray::MyArray(MyArray &t)
{
	a=new int [t.size];
	size=t.size;
	for(int i=0;i<size;i++)
		a[i]=t.a[i];
	cs=t.cs;
	flag=co=0;
}
void MyArray::getArray()
{
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element:";
		cin>>a[i];
	}
	cs=size;
}
void MyArray::setArray(int x)
{
	for(int i=0;i<size;i++)
		a[i]=x;
	cs=size;
}
void MyArray::putArray()
{
	for(int i=0;i<cs;i++)
		cout<<a[i]<<"\n";
}
void MyArray::addelement(int x)
{
	if(cs<size)
		a[cs++]=x;
	else
	{
		int *b,i;
		b=new int[size+3];
		for(i=0;i<size;i++)
			b[i]=a[i];
		b[i]=x;
		delete a;
		a=b;
		cs++;
		size=size+3;
	}
}

void main()
{
	MyArray x(8,3);
	int a;
	x[2]=5;
	x.putArray();
}