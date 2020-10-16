class CVector
{
private:
	int x,y;
public:
	CVector()
	{
		x=0;
		y=0;
	}
	CVector(int a, int b);
	CVector operator +(CVector param);
	void display();
};