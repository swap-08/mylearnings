#include<iostream>
using namespace std;
void swap_values(float& a,float& b)
{
	float temp;
	temp=a;
	a=b;
	b=temp;
}
void main()
{
	float big=2.5;
	float small=1.5;
	float& big_alias=big;
	float& small_alias=small;
	cout<<"Before swapping"<<endl;
	cout<<"Big is"<<big_alias<<endl;
	cout<<"Small is"<<small_alias<<endl;
	swap_values(big_alias,small_alias);
	cout<<"After swapping"<<endl;
	cout<<"Big is"<<big<<endl;
	cout<<"Small is"<<small<<endl;
	//cout<<"Big is"<<big_alias<<endl;
	//cout<<"Small is"<<small_alias<<endl;
}