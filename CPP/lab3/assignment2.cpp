/*************************<File Header>*************************/
/*!
@file: assignment2.cpp
@brief Abstract: Create a class for time consisting hours minutes
and seconds as data members
Author: Swapnil Kadam
Date:30/11/2013
*/
/*****************************************************************/
#include<iostream>
using namespace std;
class Time
{
private:
	int iHours,iMinutes,iSeconds;
public:
	void getTime(void)
	{
		if(60==iSeconds && 59==iMinutes)
		{
			if(iMinutes>9)
			{
			cout<<"Hours:Minutes:Minutes"<<endl;
			cout<<iHours+1<<":"<<00<<":"<<00<<endl;
			}
			else
			{
				cout<<"Hours:Minutes:Minutes"<<endl;
				cout<<"0"<<iHours+1<<":"<<00<<":"<<00<<endl;
			}
		}
		else if(60==iSeconds && iMinutes!=59)
		{
			if(iMinutes>9)
			{
				cout<<"Hours:Minutes:Minutes"<<endl;
				cout<<iHours<<":"<<iMinutes+1<<":"<<00<<endl;
			}
			else
			{
				cout<<"Hours:Minutes:Minutes"<<endl;
				cout<<"0"<<iHours<<":"<<"0"<<iMinutes+1<<":"<<00<<endl;
			}
		}

		else
		{
			if(iMinutes>9)
			{
			cout<<"Hours:Minutes:Minutes"<<endl;
			cout<<iHours<<":"<<iMinutes<<":"<<iSeconds<<endl;
			}
			else
			{
				cout<<"Hours:Minutes:Minutes"<<endl;
				cout<<"0"<<iHours<<":"<<"0"<<iMinutes<<":"<<"0"<<iSeconds<<endl;
			}

		}

	}
	void setTime(int Hours,int Minutes,int Seconds)
	{
		iHours=Hours;
		iMinutes=Minutes;
		iSeconds=Seconds;
	}
	void increment()
	{
		iSeconds++;
	}
};

void main()
{
	Time obj;
	int Hours,Minutes,Seconds;
	cout<<"Enter Time details"<<endl;
	cout<<"Enter Hours"<<endl;
	cin>>Hours;
	cout<<"Enter Minutes"<<endl;
	cin>>Minutes;
	cout<<"Enter Seconds"<<endl;
	cin>>Seconds;

	obj.setTime(Hours,Minutes,Seconds);
	obj.increment();
	obj.getTime();
	//cout<<"Time details after incrementing seconds"<<endl;
	//obj.setTime(obj.iHours,obj.iMinutes,obj.iSeconds);
}