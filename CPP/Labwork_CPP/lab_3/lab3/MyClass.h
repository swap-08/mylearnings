#include<iostream>
using namespace std;
class MyClass
{
private:
	int iMydata;
public:
	void setMyData(int iNewValue)
	{
		iMydata=iNewValue;
	}
	int getMyData(void)
	{
		return(iMydata);
	}
};