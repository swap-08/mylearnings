/*************************<File Header>****************************/
/*!
@file: lab2d.c
@Brief Abstract:
Description:Write a program that convert temperature in degree celsius to
fahrenheit 
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#define  temp2 32.00;
int main()
{
	float temperature,fahrenheit,temp1;
	printf("Enter Temperature in degree celsius \n");
	scanf("%f",&temperature);
		//calculating fahrenheit
	temp1=9.00/5.00;
	fahrenheit=temperature*temp1+temp2;
	printf("%0.2f degree Celsius converts to %0.2f degree Fahrenheit\n\n",temperature,fahrenheit);
}