/*************************<File Header>****************************/
/*!
@file: lab2c.c
@Brief Abstract:
Description:Write a program to find smallest and largest values from 10 input numbers
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
	int arr[10],i,min,m,max,n;
	printf("Enter 10 elements\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
		
		//calculating smallest number
	min=arr[0];
	for (i=1;i<10;i++) 
    {
        if (arr[i]<min) 
        {
         	min=arr[i];
        }
    } 
	printf("Smallest number is:\t%d\n\n",min);
	

				//calculating largest number
	max=arr[0];
	for (i=1;i<10;i++) 
    {
        if (arr[i]>max) 
        {
           max=arr[i];
        }
    } 
	printf("Larglest number is:\t%d\n\n",max);
}

