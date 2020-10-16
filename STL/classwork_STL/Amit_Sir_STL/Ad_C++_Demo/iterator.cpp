#include <vector> 
#include <list> 
#include <algorithm> 
#include <iostream> 
#include <iterator> 
using namespace std; 
int main() 
{ 
	vector<int> V;
	V.push_back(11); 
	V.push_back(22); 
	V.push_back(33); 
	cout << "Vector Demo...."<<endl;
	vector<int> vect;
	for(int nCnt=0;nCnt<6;nCnt++)
	{
		vect.push_back(10-nCnt);
	}
	vector<int>::iterator it;
	
	for(it=vect.begin();it!=vect.end();it++)
		cout<<*it<<" ";
	cout << endl;
	cout <<endl; 
	exit(0); 
} 
