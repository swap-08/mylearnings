/*************************<File Header>*************************/
/*!
@file: lab5b.c
@Brief Abstract:
Description:Write a program to print numbers from 1 to 1000
@note
@todo
Author:Swapnil Kadam
Date:23/11/2013
Change History: None
*/
/*****************************************************************/
#include <stdio.h>
int main () 
{
	int i,j,limit,flag;
	printf("Enter a maximum limit upto which you want to display the prime numbers : ");
	scanf("%d",&limit);
	
	//printing output

	printf("\nPrime Numbers upto %d are : \n\n",limit);
	printf("2 ");
    for (i=3;i<limit;i++) 
	{
		flag=0;
        for (j=1;j<=i;j++)
        {
            if (i%j==0)
			{
				flag++;		 //to calculate number of divisors
			}
        } 
		if(flag==2)
		{
		printf("%d ",i);	
		}
	}
	printf("\n\n");
    return 0;
}