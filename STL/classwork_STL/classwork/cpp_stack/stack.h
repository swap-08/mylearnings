#include<iostream>
using namespace std;
#define MAX 10
//using template
/*
template <class T>
class Stack
{
	private: T stack_array[MAX];

	public:	int push();
			int pop(int);
};

template <class T>
int Stack::push()
{	
	int num,top=0;

	cout<<"Enter number of elements to be push\n";
	cin>>num;

	for(int i=top;i<num;i++)
	{
		cin>>stack_array[i];
	}
	return top;
}

template <class T>
int Stack::pop(int top)
{
	int temp=stack_array[top];
	top=top+1;
	return temp;
}


*/






class Stack
{
	private: int stack_array[MAX],top;

	public:	Stack()
			{
				top=-1;
			}
//			int push();
//			int pop(int);
//			void display();
			void push();
			void pop();
			void display();

};
int Stack::push()
{	
		int num;
		if(top==MAX)
		{
			cout<<"Stack overflow.."<<endl;
		}
		else
		{
			top++;
			cin>>stack_array[top];
		}

	return top;
}

int Stack::pop(int top)
{
	int temp;
	temp=stack_array[top];
	top=top-1;
	cout<<"Element popped id :"<<temp;
	return top;
}

void Stack::display()
{
	for(int i=0;i<top;i++)
	{
		cout<<"|"<<stack_array[i]<<"   ";
	}
	cout<<endl;
}