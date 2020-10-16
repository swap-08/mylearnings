/*************************<File Header>****************************/
/*!
@file: lab4b.c
@Brief Abstract:
Description:Generate the permutation for n
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
	//function definition
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main()
{
	int number,j,i,arr[5];
	printf("Enter any number between 1 and 5\n");
	scanf("%d",&number);
	for(i=1;i<=number;i++)
	{
		printf("%d\t",i);
	}
	printf("\n");
	for(i=1;i<=number-1;i++)
	{
		j=i+1;
		swap(&i,&j);
	}
	for(i=1;i<=number;i++)
	{
		printf("%d\t",i);
	}
	

	return 0;
}
