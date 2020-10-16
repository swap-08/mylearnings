/*************************<File Header>****************************/
/*!
@file: lab3b.c
@Brief Abstract:
Description:Write a program to convert number in centimeter in to inches
and vice versa
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
void conversion_inch(float);					//function prototype
void conversion_centimeter(float);				//function prototype
int main()
{
	float centimeter,inch;
	int choice,flag=0;
	do
	{
	printf("Select an Option\n1.\tCentimeter to Inch Conversion\n2.\tInch to Centimeter Conversion\n3.\tExit\n");
	scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("\t********Centimeter to Inch Conversion******\n\n");
			printf("Enter number to be converted into Inch\n");
			scanf("%f",&centimeter);
				//calling function
			conversion_inch(centimeter);

			break;
		case 2:
			printf("\t********Inch to Centimeter Conversion******\n\n");
			printf("Enter number to be converted into Centimeter\n\n");
			scanf("%f",&inch);
				
				//calculating function
			conversion_centimeter(inch);

			break;
		case 3:
			flag=1;
			break;
		default:
			printf("\t*****INVALID CHOICE****\n");
		}
	}
	while(flag!=1);
	return 0;
}
void conversion_inch(float centimeter)		//function definition
{
	float inch,inch_temp;
	int feet;
	
	inch_temp=centimeter/CONVERTINCH;
	feet=(int)inch_temp/CONVERTCENTIMETER;
	inch=inch_temp-feet*CONVERTCENTIMETER;
	
	printf("%f centimeter is %d feet %0.1f inches\n\n",centimeter,feet,inch);
}

void conversion_centimeter(float inch)		//function definition
{
	float inch_temp,centimeter;
	int feet;
	
	centimeter=inch*CONVERTINCH;
	feet=inch/CONVERTCENTIMETER;
		
	printf("%0.1f inch is %d feet %0.1f centimeter\n\n",inch,feet,centimeter);
}