/*************************<File Header>****************************/
/*!
@file: lab5a.c
@Brief Abstract:
Description:Write a program to generate output
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
	int arr[5][5],i,j,val=2;
	for(i=1;i<5;i++)
	{
		for(j=1;j<5;j++)
		{
			//diagonal element
			if(i==j)
			{
				arr[i][j]=val;
				val++;
			}
			//non diagonal element
			if(i>j)
			{
				arr[i][j]=1;
			}
			//non diagonal element
			if(i<j)
			{
				arr[i][j]=j+1;
			}
		}
	}

			//printing matrix
	for(i=1;i<5;i++)
	{
		for(j=1;j<5;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}