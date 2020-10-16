/*************************<File Header>****************************/
/*!
@file: lab2h.c
@Brief Abstract:
Description:Write a program that convert number which is in seconds 
in to hours minutes and seconds
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#define MINUTE 60
#define HOURS 3600
void calculate_time(int);		//function prototype

int main()
{
	int no_of_seconds;
	printf("Enter number of seconds\n");
	scanf("%d",&no_of_seconds);

		//function calling
	calculate_time(no_of_seconds);

}
void calculate_time(int no_of_seconds)
{
	int hrs,min,sec,temp1,temp2; 

		//CALCULATING HOURS
	hrs=no_of_seconds/HOURS;	
	
		//CALCULATING MINUTES
	temp1=no_of_seconds-hrs*HOURS;	
	min=temp1/MINUTE;

		//CALCULATING SECONDS
	sec=temp1-min*MINUTE;

	printf("%d seconds is equivalent to %d hours %d minutes %d seconds\n\n",no_of_seconds,hrs,min,sec);
}