/*************************<File Header>****************************/
/*!
@file: lab2f.c
@Brief Abstract:
Description:Write a program to calculate area of circle
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#define PI 3.14
float area_of_circle(float);		//function prototype

int main()
{
	float radius,result;
	printf("Enter Radius of Circle\n");
	scanf("%f",&radius);

	//function calling
	result=area_of_circle(radius);

	if(1==result)
	{
		printf("Negative Values not permitted\n\n");
	}
	else
	{
		printf("Area of Circle :\t\%0.2f\n",result);
	}
}

float area_of_circle(float radius)
{
		//checking whether radius is positive or not
	if(radius<0)
	{
		return 1;
	}
	else
	{
		return(PI*radius*radius);
	}
}