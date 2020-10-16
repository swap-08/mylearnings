
#include<iostream>
using namespace std;
#define MAX 20

class Account
{
	protected: char name[MAX];
			   long acc_num;
			   double balance;

	public: Account()							//default constructor
			{
				strcpy(name,"");
				acc_num=0;
				balance=0.0;
			}


			Account(char* nm,long accno,double bal)			//parameterised constructor
			{
				strcpy(name,nm);
				acc_num=accno;
				balance=bal;
			}
		
			
			void display()					//display details
			{
				cout<<"Name :"<<name<<endl;
				cout<<"Account number :"<<acc_num<<endl;
				cout<<"Balance is :"<<balance<<endl;
			}
			
			
			void deposit()
			{
				double amount;
				cout<<"Enter Amount to deposit"<<endl;
				cin>>amount;
				balance=balance+amount;
				cout<<"Updated Balance :"<<balance<<endl<<endl;

				cout<<"Cash deposited Successfully.."<<endl;
			}


			~Account()				//destructor
			{

			}
	};


	class Savings_Acc:public Account
	{
	protected: float c_interest;

	public: Savings_Acc()
			{
				c_interest=0.0;
			}


			Savings_Acc(char* nm,long accno,double bal,float a):Account(nm,accno,bal)			//inheriting data members of base class
			{
				c_interest=a;
			}


			void withDraw()
			{
				
				float amount;

				cout<<"Enter Amount to withdraw..."<<endl;
				cin>>amount;
				
				if(amount>balance)
					cout<<"Insufficient Balance.."<<endl;
				
				else 
					balance=balance-amount;
					cout<<"Updated Balance :"<<balance<<endl<<endl;

				cout<<"Cash withdrawn Successfully.."<<endl;
			}


			void computeInterest()
			{
				if(balance<500)
					cout<<"No Interest"<<endl;
				else 
					balance=balance*c_interest+balance;
					cout<<"Updated Balance :"<<balance<<endl<<endl;

				cout<<"Cash withdrawn Successfully.."<<endl;
			}


			~Savings_Acc()
			{
			}
};


class Current_Acc:public Account
{
	protected: float minBalance;

	public: Current_Acc(char* nm,long accno,double bal,float min):Account(nm,accno,bal)			//inheriting data members of base class
			{
				minBalance=min;
			}

			void withDraw()
			{
				float amount;
				cout<<"Enter Amount to withdrawn..."<<endl;
				cin>>amount;
				
				if(balance<500 && amount>balance)
					cout<<"Insufficient Balance.."<<endl;
				else 
					balance=balance-amount;
					cout<<"Updated Balance :"<<balance<<endl<<endl;

				cout<<"Cash withdrawn Successfully.."<<endl;
			}
};