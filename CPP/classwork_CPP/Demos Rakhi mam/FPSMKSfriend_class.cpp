#include<iostream>
using namespace std;
class FPS; //Forward Declaration



class MKS
{
	private: int m;
	         int cm;
	public: MKS()//Default Constructor
		{
			m=cm=0;
		}
		MKS(int x,int y)//Parameterized Constructor
		{
			m=x;
			cm=y;
		}
		void putMKS()
		{
			cout<<"Meters:"<<m<<endl;
			cout<<"Centimeters:"<<cm<<endl;
		}
		int retm()
		{
			return m;
		}
		int retcm()
		{
			return cm;
		}
		friend double converttocm(MKS &x, FPS &y);
		double converttocm(FPS &y);
};
class FPS
{
	private: int ft, in;
	public: FPS()//Default Constructor
			{
				ft=in=0;
			}
		FPS(int x,int y)//Parameterized Constructor
		{
			ft=x;
			in=y;
		}
		void putFPS()
		{
			cout<<"Feet:"<<ft<<endl;
			cout<<"Inches:"<<in<<endl;
		}
		int retft()
		{
			return ft;
		}
		int retin()
		{
			return in;
		}
		friend double converttocm(MKS &x, FPS &y);
		friend double MKS::converttocm(FPS &y);
};

double MKS::converttocm(FPS &y)
{
	return (m*100+cm + (y.ft*12+y.in)*2.54);
}

double converttocm(MKS &x, FPS &y)
{
	return (x.m*100+x.cm + (y.ft*12+y.in)*2.54);
	//return (x.retm()*100+x.retcm() + (y.retft()*12+y.retin())*2.54);
}
void main()
{
	MKS a(5,99);
	FPS x(3,10);
	cout<<"Centimeters:"<<converttocm(a,x);
	cout<<"Centimeters:"<<a.converttocm(x);
}
