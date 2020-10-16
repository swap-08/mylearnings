#include<iostream>
#include<set>
using namespace std;

void add_String(set<int> &);
void display_String(set<int> &);
void delete_String(set<int> &);

int main()
{
	int select,flag=0;
	set<int> s;
	
	do
	{
		cout<<"Enter your choice..\n1>\tAdd Unique Strings\n2>\tDelete Strings\n3>\tDisplay\n4>\tExit\n"<<endl;
		cin>>select;
		switch(select)
		{
			case 1:
				add_String(s);
				break;
			case 2:
				delete_String(s);
				break;
			case 3:
				display_String(s);
				break;
			case 4:
				flag=1;
				break;
			default:
				cout<<"Invalid choice..\n";
				break;
		}
	}while(flag!=1);

}
void add_String(set<int> &ss)
{
	int element;
	char ch;
	do
	{
		cout<<"Enter element\n";
		cin>>element;
		ss.insert(element);
		cout<<"Do you want to continue..[Y/N]";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}


void delete_String(set<int> &ss)
{
	int element;
	char ch;
	do
	{
		cout<<"Enter element to delete\n";
		cin>>element;
		ss.erase(element);
		cout<<"Do you want to continue..[Y/N]";
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');
}


void display_String(set<int> &ss)
{
	set<int>::iterator i;
	for(i=ss.begin();i!=ss.end();i++)
	{
		cout<<*i<<"  ";
	}
	cout<<endl;
}