/*************************<File Header>*************************/
/*!
@file: section1.cpp
@brief Abstract: Create a time class that include member values
for hours,minutes and seconds
a.write appropriate constructor
b.error checking
c.operator overloading <<
Author: Swapnil Kadam
Date:13/12/2013
*/
/*****************************************************************/

#include"section1.h"		//INCLUDING HEADER FILE

Time::Time()				//DEFAULT CONSTRUCTOR DEFINITION
{
	Hours=0;
	Minutes=0;
	Seconds=0;
}


Time::Time(int iHours, int iMinutes, int iSeconds)	//PARAMETERISED CONSTRUCTOR DEFINITION
{
	Hours=iHours;
	Minutes=iMinutes;
	Seconds=iSeconds;
}


/*************************<Function Header>*************************/
/*!
@fn: void Time::Check_all_fields()
@brief ABSTRACT:

Description: CHECKING FOR INCORRECT ENTRY FROM USER 
@param:  NO PARAMETER
@return :  NO RETURN VALUE
@remarks :NONE
@warning :NONE
@see :NONE
*/
/*****************************************************************/

void Time::Check_all_fields()					//MEMBER FUNCTION FOR CHECKIN ALL FIELDS OF TIME VALUES
{
	
	if(Hours<MIN_RANGE OR Hours>MAX_HOUR_RANGE)		//CHECK HOUR RANGE BETWEEN 0-23
	{

		cout<<"Incorrect Entry of Hours"<<endl<<"Please enter hours between 0-23\t(American Standard)"<<endl;
		exit(1);	//EXIT FROM PROGRAM WITH ERROR
	}
	
	else if(Minutes<MIN_RANGE OR Minutes>MAX_RANGE)		//CHECK MINUTE RANGE BETWEEN 0-59
	{

		cout<<"Incorrect Entry of Minutes"<<endl<<"Please enter Minutes between 0-59"<<endl;
		exit(1);	//EXIT FROM PROGRAM WITH ERROR
	}
	
	else if(Seconds<MIN_RANGE OR Seconds>MAX_RANGE)		//CHECK SECOND RANGE BETWEEN 0-59
	{

		cout<<"Incorrect Entry of Seconds"<<endl<<"Please enter Seconds between 0-59"<<endl;
		exit(1);	//EXIT FROM PROGRAM WITH ERROR
	}
	
	else
	{
		cout<<"Time enetered successfulle..."<<endl;
	}
}
ostream& operator<<(ostream &out, Time &t)			//INSERTION OPERATOR OVERLOADING USINF FRIEND FUNCTION
{
	out<<"*****TIME*******"<<endl;
	out<<"HH:MM:SS"<<endl<<t.Hours<<":"<<t.Minutes<<":"<<t.Seconds<<endl;
	return out;
}


//MAIN
void main()
{
	Time a(12,12,12);		//CREATING INSTANCE OF CLASS AND CALLING PARAMETERISED CONSTRUCTOR

	a.Check_all_fields();	//CHECK FOR ANY ERROR
	
	//USE OF INSERTION OPERATOR OVERLOADING

	cout<<a;
}
