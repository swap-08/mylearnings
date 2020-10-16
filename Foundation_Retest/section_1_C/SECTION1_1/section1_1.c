/*************************<File Header>*************************/
/*!
@file: section1_1.c
@brief Abstract: Use of structure

Description:	Write a c program to perform withdraw functionality 
for ATM system.Accept the details and withdraw the amount if 
amount is greater then current balance then display error message.
Author: Swapnil Kadam
Date:09/12/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>

/*GLOBAL VARIABLE*/
int withdrawal_amount;

/*************************<Structure Header>***********************/
/*!
@struct: struct Customer
@brief ABSTRACT:

Description: structure containing account number,name of customer
and current balance
*/
/*****************************************************************/
struct Customer
{
	int account_number;
	char name[30];
	float current_balance;
};

int main()
{
	/* STRUCTURE VARIABLE DECLARATION */
	struct Customer s;


	/* GETTING CUSTOMER DETAILS */
	printf("**********Enter Customer details..************\n");

	printf("Enter account number\n");
	scanf("%d",&s.account_number);

	printf("Enter Name of the Account Holder\n ");
	scanf("%s",s.name);

	printf("Enter Current Balance of the Account Holder\n ");
	scanf("%f",&s.current_balance);


	/* DISPLAYING GETTING CUSTOMER DETAILS */
	printf("*************Customer details*******************\n");

	printf("\n Account number \n %d",s.account_number);

	printf("\n Name of the Account Holder \n %s",s.name);

	printf("\n Current Balance of the Account Holder \n %0.2f ",s.current_balance);


	/* WITHDRAWAL OF AMOUNT */
	printf("\n\n*************Withdrawal of Amount*******************\n");

	printf("\n EnterAmount to be withdrawn \n ");
	scanf("%d",&withdrawal_amount);					//WITHDRAWAL AMOUNT



	/* CHECK WHETHER AMOUNT IS GREATER THEN CURRENT BALANCE OR NOT*/
	if(s.current_balance<withdrawal_amount)
	{
		printf("\nInsufficient Balance.. \n Transaction Terminated.. \n\n");		//CURRENT BALANCE IS LESS THEN WITHDRAWAL AMOUNT
	}
	else
	{
		s.current_balance=s.current_balance-withdrawal_amount;						//CURRENT BALANCE IS GREATER THEN WITHDRAWAL AMOUNT
		printf("\n Remaining Balance : \t %0.2f \n\n",s.current_balance);
		printf("\n Transaction Successfully Completed.. \n\n Thank You for visiting our ATM \n\n");
	
	}
	return 0;	//RETURN WITHOUT ERROR
}