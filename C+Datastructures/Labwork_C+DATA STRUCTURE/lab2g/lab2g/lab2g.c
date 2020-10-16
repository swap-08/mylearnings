/*************************<File Header>****************************/
/*!
@file: lab2g.c
@Brief Abstract:
Description:Write a program that convert  number in centimeter in to inches and feet
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#define CONVERTINCH 2.54
#define CONVERTCENTIMETER 12
void conversion(float);		//function prototype
int main()
{
	float centimeter;
	int feet,choice,flag=0;

	printf("\t********Centimeter to Inch Conversion******\n\n");
	printf("Enter number to be converted into Inch\n");
	scanf("%f",&centimeter);
			//function calling
	conversion(centimeter);
}
void conversion(float centimeter)		//function definition
{
	float inch,inch_temp;
	int feet;
	inch_temp=centimeter/CONVERTINCH;			
	feet=(int)inch_temp/CONVERTCENTIMETER;		
	inch=inch_temp-feet*CONVERTCENTIMETER;
	printf("%0.1f centimeter is %d feet %0.1f inches\n\n",centimeter,feet,inch);
}