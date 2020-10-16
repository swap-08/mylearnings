#include<iostream>
#include<fstream>
using namespace std;
void main()
{
	char ch;
	ofstream ofs("D:\\a.txt");
	
	cout<<"Enter contents for file: "<<endl;
	ch=cin.get();
	
	while(ch!=26) //^Z
	{
		ofs.put(ch);
		ch=cin.get();
	}
	ofs.close();
	cout<<"File Saved\n";



	ifstream ifs("D:\\a.txt");
	cout<<"\nContents of file:"<<endl;
	ch=ifs.get();
	while(!ifs.eof())
	{
		cout<<ch;
		ch=ifs.get();
	}
	ifs.close();
}