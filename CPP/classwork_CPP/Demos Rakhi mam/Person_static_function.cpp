#include<iostream>
using namespace std;
#include<string.h>
class Person
{
	private: char n[30];
			    int age;
				static int count;
	public: void getPerson();
			   void putPerson() const ;
			   Person& setPerson(char *, int);
			   void static displaycount()
			   {
				   cout<<"No. of Persons:"<<count<<endl;
			   }
};
void Person::getPerson()
{
	cout<<"Enter Name:";
	cin>>this->n;
	cout<<"Enter Age:";
	cin>>this->age;
	count++;
}
void Person::putPerson() const
{
	cout<<"Name:"<<n<<endl;
	cout<<"Age:"<<age<<endl;
}
Person& Person::setPerson(char *mn, int mage)
{
	strcpy(n,mn);
	age=mage;
	count++;
	return *this;
}
//int Person::count;
void main()
{
	Person p1, p2;
	p1.getPerson();
	Person::displaycount();
	p2.setPerson("Ram",25).putPerson();
	Person::displaycount();
	p1.putPerson();
}