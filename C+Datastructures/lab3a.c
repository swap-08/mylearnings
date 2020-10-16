/*************************<File Header>****************************/
/*!
@file: lab3a.c
@Brief Abstract:
Description:Write a program to calculate simple interest 
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#include<math.h>
#define MAX 100
int main()
{
	int principle,rate_of_interest,year;
	float simple_interest; 
	printf("Enter Principle amount\n");
	scanf("%d",&principle);
	printf("Enter Rate of Interest\n");
	scanf("%d",&rate_of_interest);
	printf("Enter Number of Years\n");
	scanf("%d",&year);
			
	//calculating simple_interest
	simple_interest=((float)principle*(float)rate_of_interest*(float)year)/MAX;
	
	printf("Simple Interest :%0.2f\n",simple_interest);
	return 0;
}