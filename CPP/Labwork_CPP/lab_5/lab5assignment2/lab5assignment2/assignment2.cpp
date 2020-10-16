/*************************<File Header>*************************/
/*!
@file: assignment2.cpp
@brief Abstract: Use of constructor for operator overloading
Author: Swapnil Kadam
Date:04/12/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;

class cstring
{
	private: char* str;
	public: cstring()						//default constructor
			{
				str=new char[1];
				strcpy(str,"");
			}
		
		
			cstring(int a)					//parameterised constructor
			{
				cstring t;
				t.str=new char[a];
				for(int i=0;i<a;i++)
				{
					t.str[i]='_';
				}
				t.str[a]='\0';
				t.display();
			}


			
			cstring(char ch,int a)					//parameterised constructor
			{
				cstring t;
				t.str=new char[a];
				for(int i=0;i<a;i++)
				{
					t.str[i]=ch;
				}
				t.str[a]='\0';
				t.display();
			}
			
			
			cstring(char string[])					//parameterised constructor
			{
				str=new char[strlen(string)];
				for(int i=0;i<strlen(string);i++)
				{
					str[i]=string[i];
				}
				str[strlen(string)]='\0';
				display();
			}
			
			
			void display()						//display function
			{
				for(int i=0;i<strlen(str);i++)
				{
					cout<<str[i];
				}
				cout<<endl;
			}
			
			
			~cstring()						//destructor
			{
				//delete []str;
			}
			
			void operator =(cstring& x)
			{
				cout<<x.str;

			}


			char operator [](int a)						//subscript operator overloading
			{
				return str[a];
			}
			
			
			void operator ==(cstring& x)						//equality operator overloading
			{
				int a=(strcmp(str,x.str));
				if(0==a)
				{
					cout<<"strings are same"<<endl;
				}
				else
				{
					cout<<"strings are not same"<<endl;
				}
			}
			
			
			void operator +=(cstring& x)						//appending operator overloading
			{
				strcat(str,x.str);
				display();

			}
			void operator <=(cstring& x)						//string size check operator overloading
			{
				int len1=strlen(str);
				int len2=strlen(x.str);
				if(len1<=len2)
					cout<<"TRUE"<<endl;
				else
					cout<<"FALSE"<<endl;
			}
};
void main()
{
	cstring c2(10),c3('*',10),c4("swapnil"),c5("kadam"),c6;

	//calling operator overloading

	cout<<"*******c4==c5*******"<<endl;		//equality
	c4==c5;
	
	cout<<"*******c4<=c5*******"<<endl;		//less then or equal to
	c4<=c5;
	
	cout<<"*******c4=c5*******"<<endl;		//check for same string
	c4=c5;
	
	cout<<"*******c4+=c5*******"<<endl;		//append string
	c4+=c5;
	
	char c=c4[1];							//subscript
	cout<<endl<<"Character at position 1"<<c<<endl;
	
}