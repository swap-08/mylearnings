#include<iostream>
using namespace std;
class CSquare;
class CRectangle
{
private:
	int width,height;
public:
	int area(void)
	{
		return width*height;
	}
	void convert(CSquare);
};
class CSquare
{
private:
	int side;
public:
	void set_side(int a)
	{
		side=a;
	}
	friend class CRectangle;
};