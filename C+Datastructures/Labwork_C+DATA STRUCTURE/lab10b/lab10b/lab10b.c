/*************************<File Header>*************************/
/*!
@file: lab10b.c
@Brief Abstract:
Description:Write a program that read a number that says how many integers are
to be stored in array
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
	int size,arr[10],i;
	printf("Enter size of array\n");
	scanf("%d",&size);
	printf("Enter elements\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array elements are \n");
	for(i=0;i<size;i++)
	{
		printf("%d\n",arr[i]);
	}
}