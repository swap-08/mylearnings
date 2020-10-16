/*************************<File Header>*************************/
/*!
@file: lab5d.c
@Brief Abstract:
Description:Check whether a number is an Armstrong number or not
@note
@todo
Author:Swapnil Kadam
Date:23/11/2013
Change History: None
*/
/*****************************************************************/

#include<stdio.h>
int armstrong(int);		//function prototype
int main()
{
	int number,check;
	printf("Enter any positive number\n");
	scanf("%d",&number);
	check=armstrong(number);
	if(0==check)
	{
		printf("Number is a Armstrong number\n");
	}
	else
		printf("Number is not a Armstrong number\n");
	return 0;
}
int armstrong(int num)		//function definition
{
	int temp[5],cube=0,count=0,i,dumy;
	dumy=num;
			//calcultiong each digit of number
	while(num!=0)
	{
		temp[count]=num%10;
		num=num/10;
		count++;
	}
			//calculating cube of each digit
	for(i=0;i<count;i++)
	{
		cube=cube+temp[i]*temp[i]*temp[i];
	}
			//checking for armstrong number
	if(cube==dumy)
		return 0;
	else
		return 1;
}