#include<iostream.h>
void main()
{
	int x;
	cout<<"Enter any value:";
	cin>>x;
	try
	{
		if(x>0)
		{
			throw x;
		}
		else
			if(x<0)
			{
				throw 'x';
			}
			else
			{
				throw "Zero";
			}
	}
	catch(int a)
	{
		cout<<"In catch 1";
	}
	catch(char a)
	{
		cout<<"In catch 2";
	}
	catch(...)
	{
		cout<<"In generic catch";
	}
}