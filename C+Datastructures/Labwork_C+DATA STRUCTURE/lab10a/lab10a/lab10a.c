/*************************<File Header>*************************/
/*!
@file: lab10a.c
@Brief Abstract:
Description:Write a program that read a number from command line
input and generate a random floating point number in the range 0
@note
@todo
Author:Swapnil Kadam
Date:27/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char *argv[])
{
	float random;
	int number;
	printf("Enter any number\n");
	scanf("%d",&number);
		//random number
	random=(float)rand(number)/(float)RAND_MAX/(float)number;
	printf("%f\n",random);
}