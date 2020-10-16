/*************************<File Header>*************************/
/*!
@file: lab12extra_assignment.c
@Brief Abstract:
Description:Write a program which take stwo file names from command line and
compares them character by character and displays if both are same.
@note
@todo
Author:Swapnil Kadam
Date:27/11/2013
Change History: None
*/
/*****************************************************************/
#include <stdio.h>
#include <stdlib.h>

int **create_array(int,int);
void display_array(int **,int,int);
int **sort_row_wise(int **,int,int);
int **sort_column_wise(int **,int,int);

int main(void)
{
	int r,c,option,i,j,k;
	int **original_array;		//POINTER CREATION
	printf("Enter row size:");
	scanf("%d",&r);
	printf("Enter column size:");
	scanf("%d",&c);

	printf("\n\n");

	original_array=create_array(r,c);
	
	display_array(original_array,r,c);

	do
	{
		printf("\nEnter your choice : \n\n1)Row Wise Sorting\n2)Column Wise Sorting\n3)Display Array\n4)Exit\n\nYour Option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:	original_array=sort_row_wise(original_array,r,c);
					printf("Row Wise Sorting Completed..!!\n\n");
					break;

			case 2: original_array=sort_column_wise(original_array,r,c);
					printf("Column Wise Sorting Completed..!!\n\n");
					break;

			case 3: display_array(original_array,r,c);
					break;

			case 4: printf("Thank you..!!\n\n");
					break;

			default:printf("Enter proper option..!!\n\n");
					break;

		}
	}while(option != 4);
	free(original_array);
	return 0;
}

int **create_array(int row,int column)
{
	int **arr;
	int i,j;
	arr=(int **)malloc(row*sizeof(int *));
	if (arr==NULL)
	{
		printf("Insufficient Memory");
	}
	for(i=0;i<row;i++)
	{
		arr[i]=(int*)malloc(column*sizeof(int));
		if (arr==NULL)
		{
			printf("Insufficient Memory");
		}
	}
	for (i=0;i<row;i++)
	{
		for (j=0;j<column;j++)
		{
			printf("Enter element [%d][%d] : ",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}
	}

	printf("\n\n");

	return arr;
}

void display_array(int **arr,int row,int column)
{
	int i,j;
	printf("Elements of the Array are : \n");

	for (i=0;i<row;i++)
	{
		for (j=0;j<column;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
}

int **sort_row_wise(int **arr,int row,int column)
{
	int i,j,k;
	for(k=0;k<row;k++)
	{
		for(i=0;i<column-1;i++)
		{
			for (j=0;j<column-1-i;j++)
			{
				if (arr[k][j]>arr[k][j+1])
				{
					int temp=arr[k][j];
					arr[k][j]=arr[k][j+1];
					arr[k][j+1]=temp;
				}
			}
		}
	}
	return arr;
}
int **sort_column_wise(int **arr,int row,int column)
{
	int i,j,k;
	for(k=0;k<column;k++)
	{
		for(i=0;i<row-1;i++)
		{
			for (j=0;j<row-1-i;j++)
			{
				if (arr[j][k]>arr[j+1][k])
				{
					int temp=arr[j][k];
					arr[j][k]=arr[j+1][k];
					arr[j+1][k]=temp;
				}
			}
		}
	}
	return arr;
}