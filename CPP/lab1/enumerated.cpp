#include<iostream>
using namespace std;
int iDay=7;		//global value
void main()
{
	enum days_of_week{Sun,Mon,Tue,Wed,Thu,Fri,Sat};
		//iDay is locat var and ::iDay is global var
	for(int iDay=0;iDay<::iDay;iDay++)		//iDay is local ::iDay is global
	{
		if(iDay==Sun)			//same as if(iDay==0)
			cout<<"Holiday"<<endl;
		else
			cout<<"Oh No! Working Day"<<endl;
	}
}



