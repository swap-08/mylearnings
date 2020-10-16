#include"stack.h"
void main()
{
	Stack s;
	int top,pop_element,flag=0,select;
	char ch='y';
	do
	{
		cout<<"1> push\n2> pop\n3>display\n4>exit"<<endl;
		cin>>select;
		switch(select)
		{
		case 1:
			cout<<"PUSH"<<endl;
			top=s.push();
			break;
		case 2:
			if(top==-1)
			{
				cout<<"Stack underflow.."<<endl;
			}
			else
			{
				cout<<"POP"<<endl;
				top=s.pop(top);
				cout<<"Top is :"<<top<<endl;
			}
			break;
		case 3:
			cout<<"DISPLAY"<<endl;
			s.display();
			break;
		case 4:
			flag=1;
			break;
		default:
			cout<<"Invalid Choice..";
		}
	}
	while(flag!=1);	
}