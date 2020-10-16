#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
void main()
{
	fstream fs;
	fs.open("a.txt",ios::out);
	char ch;
	cout<<"Enter text:";
	ch=getche();
	while(ch!=26)
	{
		if(ch==13)
		{
			fs<<"\n";
			cout<<"\n";
		}
		else
			   fs<<ch;
		ch=getche();
	}
	fs.close();
	cout<<"\b ^Z File Saved\n";

	

	fs.open("a.txt",ios::in);
	ch=fs.get();
	while(!fs.eof())
	{
		cout<<ch;
		ch=fs.get();
	}
	fs.close();
}