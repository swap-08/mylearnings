/*************************<File Header>****************************/
/*!
@file: lab2b.c
@Brief Abstract:
Description:Write a program to calculate sum,average, and sum of squares
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
		//function prototype
float calculatesum(float x,float y);
float calculateavg(float x,float y);
float calculatesumsqr(float x,float y);
int main()
{
	float num1,num2,avg,sum,sumsqr;
	printf("Enter two digit\n");
	scanf("%f",&num1);
	scanf("%f",&num2);

	sum=calculatesum(num1,num2);
	avg=calculateavg(num1,num2);
	sumsqr=calculatesumsqr(num1,num2);
	
	printf("\nSum of two digit\n%f",sum);
	printf("\nAverage of two digit\n%f",avg);
	printf("\nSum of square of two digit\n%f\n",sumsqr);
}
float calculatesum(float x,float y)
{
	return(x+y);
}
float calculateavg(float x,float y)
{
	return((x+y)/2);
}
float calculatesumsqr(float x,float y)
{
	return(x*x+y*y);
}