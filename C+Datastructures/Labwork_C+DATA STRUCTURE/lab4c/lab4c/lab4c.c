/*************************<File Header>****************************/
/*!
@file: lab4c.c
@Brief Abstract:
Description:Write a program to Print a palindrome of MALAYALAM
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
int main()
{
	char palindrome[10]={'M','A','L','A','Y','A','L','A','M','\0'};
	int i,j,k,start=0,end=9;
			//Palindrome construction
	for(i=0;i<5;i++)
	{
		for(j=start;j<end;j++)
		{
			printf("%c",palindrome[j]);
		}
		printf("\n");
		start++;
		end--;
		//adding space for each line
		for(k=start;k>0;k--)
		{
			printf(" ");
		}
	}	
	return 0;
}