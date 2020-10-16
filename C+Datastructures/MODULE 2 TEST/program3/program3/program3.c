/*************************<File Header>*************************/
/*!
@file: program3.c
@brief Abstract: Use of structure
Description:An inventory record contains itemcode,name etc
and perform sorting and searching
@note
@todo
Author: Swapnil Kadam
Date:28/11/2013
Change History:
*/
/*****************************************************************/

#include <stdio.h>
#include<string.h>
#define SIZE 30
		
/*function prototype*/

void add_details(struct record *,int);
void display_details(struct record *,int );
void sort_price(struct record *items,int );
void search_items(struct record *,int );


/*************************<Structure Header>***********************/
/*!
@struct: struct record
@brief ABSTRACT:

Description: structure containing records
item_code,item_name,item_price and reorder_level;
@remarks
@warning
@see
*/
/*****************************************************************/

struct record
{
	int item_code;
	char item_name[SIZE];
	float item_price;
	int reorder_level;
};

int main()
{
	int choice,i,flag=0,number=0;
	struct record s[SIZE];
	do
	{
		printf("Enter your choice\n1.\tADD DETAILS\n2.\tDISPLAY DETAILS\n3.\tVIEW DETAILS IN SORTED ORDER OF NAME\n4.\tVIEW DETAILS IN SORTED ORDER OF ROLL NUMBER\n5.\tEXIT\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			number++;
			add_details(s,number);
			break;
		case 2:
			display_details(s,number);
			break;
		case 3:
			sort_price(s,number);
			break;
		case 4:
			search_item(s,number);
			break;
		case 5:
			flag=1;
			break;
		default:
			printf("Invalid choice");
			break;
		}
	}
		while(flag!=1);
		return 0;
}
/*************************<Function Header>*************************/
/*!
@fn: void add_details(struct record *items,int num)
@brief ABSTRACT:

Description: Adding details of item sets
@param:  struct record *items,int num
@return :  
@remarks
@warning
@see
*/
/*****************************************************************/

void add_details(struct record *items,int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("Enter Item Code\n");
		fflush(stdin);
		scanf("%s",items[i].item_code);
		printf("Enter Item Name\n");
		fflush(stdin);
		scanf("%s",items[i].item_name);
		printf("Enter Item Price\n");
		scanf("%f",items[i].item_price);
		printf("Enter Reorder Level\n");
		scanf("%d",items[i].reorder_level);
	}
	printf("Successfully Entered all the details\n\n");
}

/*************************<Function Header>*************************/
/*!
@fn: void display_details(struct record *items,int number)
@brief ABSTRACT:

Description:  Display details 
@param:  struct record *items,int number
@return : 
@remarks
@warning
@see
*/
/*****************************************************************/
void display_details(struct record *items,int number)
{
	int i;
	for(i=0;i<number;i++)
	{
		printf("Enter Item Code\t%d\n",items[i].item_code);
		printf("Enter Item Name\t%s\n",items[i].item_name);
		printf("Enter Item Price\t%f\n",items[i].item_price);
		printf("Enter Reorder Level\t%d\n",items[i].reorder_level);
	}
		printf("Successfully displayed all the details\n\n");
}

/*************************<Function Header>*************************/
/*!
@fn: void sort_price(struct record *items,int num)
@brief ABSTRACT:

Description:  Sorting as per price 
@param:  struct record *items,int num
@return : 
@remarks
@warning
@see
*/
/*****************************************************************/
void sort_price(struct record *items,int num)
{
	int i,j;
	struct record temp;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1;j++)
		{
			if(items[i].item_price>items[i+1].item_price)
			{
				temp=items[i];
				items[i]=items[i+1];
				items[i+1]=temp;
			}
		}
	}
	printf("\n\n\t....SORTING COMPLETE.....\n\n");
}
/*************************<Function Header>*************************/
/*!
@fn: void search_items(struct record *items,int num)
@brief ABSTRACT:

Description:  searching items
@param:  (struct record *items,int num)
@return :  
@remarks
@warning
@see
*/
/*****************************************************************/
void search_items(struct record *items,int num)
{
	int i,j;
	struct record temp;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1;j++)
		{
			if(items[i].rollno > items[i+1].rollno)
			{
				temp=items[i];
				items[i]=items[i+1];
				items[i+1]=temp;
			}
		}
	}
	printf("\n\n\t....SEARCHING COMPLETE.....\n\n");
}
