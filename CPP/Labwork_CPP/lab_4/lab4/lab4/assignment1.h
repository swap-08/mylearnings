#include<iostream>
using namespace std;
class employee
{
private:
	long empcode;
	double salary;
	char* name;
public:
	employee();
	employee(long,double,char*);
	long getEmpcode();
	double getSalary();
	char* getName();
	void displayDetails();
	/*~employee()
	{
		delete []name;
	}*/
};