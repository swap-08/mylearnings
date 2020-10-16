#include<iostream>
using namespace std;

#define OR ||
#define MIN_RANGE 0
#define MAX_HOUR_RANGE 24
#define MAX_RANGE 60

class Time
{
				//DECLARATION OF MEMBERFUNCTIONS AS PUBLIC
	public:   Time();											//DEFAULT CONSTRUCTOR

			  Time(int iHours,int iMinutes,int iSeconds);		//PARAMETERISED CONSTRUCTOR

			  void Check_all_fields();							//MEMBER FUNCTION FOR CHECKING TIME VALUES

			  friend ostream& operator<<(ostream &out, Time &t);	//FRIEND FUNCTION FOR INSERTION OPERATOR OVERLOADING
			  
			  ~Time()											//DESTRUCTOR
			  {
			  }


				//DECLARATION OF DATAMEMBERS AS PRIVATE
	private:  int Hours;
			  int Minutes;
			  int Seconds;
};


