#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX 20
void main()
{
	//write file
	ofstream outf("item.txt");
	
	char cItemName[MAX];
	float fItemCost;


	for(int iCounter=0;iCounter<2;iCounter++)
	{
		cout<<"enter itemm name"<<endl;
		cin>>cItemName;
		
		outf<<cItemName<<" ";
		
		cout<<"enter cost"<<endl;
		cin>>fItemCost;
		
		outf<<fItemCost<<" "<<endl;


	}
	outf.close();
	
	
	//read file
	ifstream inf("item.txt");
	
	for(int iCounter=0;iCounter<2;iCounter++)
	{
		cout<< "itemm name"<<endl;
		
		inf>>cItemName;
		cout<<cItemName<<endl;
		
		cout<<"cost"<<endl;
		
		inf>>fItemCost;

		cout<<fItemCost<<endl;
	}
	inf.close();
}





