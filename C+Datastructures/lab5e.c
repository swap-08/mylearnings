/*************************<File Header>*************************/
/*!
@file: lab5e.c
@Brief Abstract:
Description:Write a program to find Highest Common Factor and
Least Common Factor
@note
@todo
Author:Swapnil Kadam
Date:23/11/2013
Change History: None
*/
/*****************************************************************/
#include <stdio.h>
int main()
{   
	int  num1,num2,gcd,lcm,i;	
	printf("Enter two numbers : \n"); 
	printf("Enter Number 1 : ");
	scanf("%d",&num1);
	printf("Enter Number 2 : ");
	scanf("%d",&num2);
	
	//logic to find gcd
	
	for(i=1;i<=num1||i<=num2;i++)
	{
		if(num1%i==0 && num2%i==0)
		{
			gcd=i;
		}
	}

	//calculation of lcm

	lcm=(num1*num2)/gcd;
	
	//printing the result
	
	printf("\nGCD of the two numbers is %d",gcd);
	printf("\nLCM of the two numbers is %d\n\n",lcm);
	return 0;
}
 
