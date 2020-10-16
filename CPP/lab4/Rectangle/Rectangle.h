#include<iostream>
using namespace std;
class CRectangle
{
private:
	int width,height;
public:
	void setValues(int a,int b);
	int Area(void);
	friend CRectangle duplicate(CRectangle);
};
	
