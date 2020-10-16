#include <iostream>
#include <vector>
#include <string>
using namespace std;
void main()
{
	vector<string> SS;
	SS.push_back("The number is 10");
	SS.push_back("The number is 20");
	SS.push_back("The number is 30");
	SS.push_front("swapnil 10");
	cout << "Loop by index:" << endl;
	int ii;
	for(ii=0; ii < SS.size(); ii++)
	{
		cout << SS[ii] << endl;
	}
	cout << endl << "Constant Iterator:" << endl;
	vector<string>::const_iterator cii;
	for(cii=SS.begin(); cii!=SS.end(); cii++)
	{
		cout << *cii << endl;
	}
}
