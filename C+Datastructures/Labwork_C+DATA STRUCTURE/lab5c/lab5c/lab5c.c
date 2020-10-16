/*************************<File Header>*************************/
/*!
@file: lab5c.c
@Brief Abstract:
Description:Read a positive integer value and compute the following
if number is even,halve it;if it odd multiply by 3 and add 1.
repeat untill the value is 1
@note
@todo
Author:Swapnil Kadam
Date:23/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
int main()
{
	int number,flag=0,count=0;
	printf("Enter a number\n");
	scanf("%d",&number);
	printf("Initial value is :%d\n",number);


	do
	{
		if(number<1)
		{
			printf("Error....\n");
			flag=1;
		}
		if(0==(number%2))			//even
		{
			number=number/2;
			if(number==1)
			{
				printf("Final value is 1,number of steps :%d\n",count+1);
			}
			else
			{
				printf("%d\n",number);
				count++;
			}
		}
		else						//odd
		{
			number=(number*3)+1;
			printf("%d\n",number);
			count++;
		}
	}
	while(number!=1 && flag!=1);

	return 0;
}