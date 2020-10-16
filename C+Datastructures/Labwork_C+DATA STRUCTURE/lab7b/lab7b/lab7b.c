/*************************<File Header>****************************/
/*!
@file: lab7b.c
@Brief Abstract:
Description:Implementation of Selection Sort
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
void selectionsort(int *,int);
void display(int *,int);
int main()
{
	int arr[10];
	int i,j,temp,size;
	printf("Enter array size\n");
	scanf("%d",&size);
	printf("Enter element\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
		//function calling

	selectionsort(arr,size);
	display(arr,size);
}
		//sorting
	void selectionsort(int *a,int size)
	{	
		int i,j,temp;
		for(i=0;i<size;i++)
		{
			j=i-1;
			temp=a[i];
		while(temp<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		}
		printf("Sorted successfully...\n");
	}
			//display
	void display(int *a,int size)
	{
		int i;
		printf("Sorted elements are.....\n");
		for(i=0;i<size;i++)
		{
			printf("%d\n",a[i]);
		}
	}