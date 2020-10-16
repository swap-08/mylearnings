#include"assignment1.h"
//#include<string>
/* default constructor*/
employee::employee()
{
	empcode=0;
	salary=0.0;
	//strcpy(name,NULL);
}
employee::employee(long ecode,double sal,char* nam)
{
	name=new char[strlen(nam)];
	empcode=ecode;
	salary=sal;
	strcpy(name,nam);
}
long employee::getEmpcode()
{
	//cout<<"Enter employee code"<<endl;
	//cin>>empcode;
	return empcode;
}
double employee::getSalary()
{
	//cout<<"Enter employee salary"<<endl;
	//cin>>salary;
	return salary;
}
char *employee::getName()
{
	//char refname[20];
	//cout<<"Enter employee code"<<endl;
	//cin>>refname;
	//for(int i=0;i<strlen(refname);i++)
	//{
	//	name[i]=refname[i];
	//}
	return name;
}
void employee::displayDetails()
{
	cout<<"Employee name   :"<<name<<endl;
	cout<<"Employee code   :"<<empcode<<endl;
	cout<<"Employee salary :"<<salary<<endl;
}

void main()
{
	//employee e;
	long code;
	double sal;
	char* name;

	employee e(11,25000,"swapnil");

	code=e.getEmpcode();
	cout<<"empcode :"<<code<<endl;
	sal=e.getSalary();
	cout<<"empsalary :"<<sal<<endl;
	name=e.getName();

	e.displayDetails();
}