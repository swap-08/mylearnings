/*************************<File Header>*************************/
/*!
@file: program1.c
@brief Abstract: Use of singly linked list
Description:Create a structure to imlpement singly linked list 
and write function to add a node
to the end of the list
@note
@todo
Author: Swapnil Kadam
Date:28/11/2013
Change History:
*/
/*****************************************************************/

#include<stdio.h>
#define size 10
		
	//function prototype

struct node *getNode();
struct node *insertNode(struct node *,struct node *);
void *displayNode(struct node *);
void *displayNode_Reverse(struct node *);

/*************************<Structure Header>***********************/
/*!
@struct: struct node
@brief ABSTRACT:

Description: structure containing only record i.e roll number
and a pointer i.e *next
@remarks
@warning
@see
*/
/*****************************************************************/

struct node
{
	int roll_no;
	struct node *next;
};


int main()
{
	//VARIABLE DECLARATION
	int select,flag=0,i;
	//STRUCTURE POINTER DECLARATION
	struct node *start=NULL,*newrec=NULL;
	do
	{
		printf("Enter your choice :\n1)\tInsert Element\n2)\tDisplay\n3)\tDisplay Reverse\n4)\tExit\n");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				for(i=0;i<size;i++)
				{
					start=insertNode(start,newrec);
				}
				printf("Insertion Successfully Completed\n\n");
				break;

			case 2:
				displayNode(start);
				break;
			case 3:
				displayNode_Reverse(start);
				break;
			case 4:
				flag=1;
				break;
			default:
				printf("Invalid Choice\n");

		}
	}
	while(flag!=1);	//END OF DO WHILE
	return 0;
}
		//NODE CREATION
/*************************<Function Header>*************************/
/*!
@fn: struct node *getNode()
@brief ABSTRACT:

Description:  Creation of linked list node 
@param:  
@return :  newrec
@remarks
@warning
@see
*/
/*****************************************************************/
	
	struct node *getNode()
	{
		struct node *newrec;	
		newrec=(struct node *)malloc(sizeof(struct node));
		newrec->next=NULL;
		printf("Node Successfully created\n\n");
		return newrec;
	}

			//INSERTION
/*************************<Function Header>*************************/
/*!
@fn: struct node *insertNode(struct node *,struct node *)
@brief ABSTRACT:

Description:  Insertion of linked list data 
@param:  struct node *start,struct node *newrec
@return :  start
@remarks
@warning
@see
*/
/*****************************************************************/

	struct node *insertNode(struct node *start,struct node *newrec)
	{
		struct node *temp=NULL,*prev=NULL;

		
		//adding node

			newrec=(struct node *)malloc(sizeof(struct node));
			newrec->next=NULL;

			printf("Enter Linked list Data\t:\n");
			scanf("%d",&newrec->roll_no);
			
			
			if(start==NULL)
			{
				start=newrec;
			}
			else
			{
				temp=start;
				prev=start;
				while(temp->roll_no < newrec->roll_no)				// && temp->next!=NULL)  temp->next!=NULL)
				{
					prev=temp;
					temp=temp->next;
					if(temp==NULL)
						break;
				}
					
				if(temp==start)										//first element
				{
					newrec->next=start;
					start=newrec;
				}
				else if(temp==NULL)									//last element
				{
					prev->next=newrec;
		
				}
				else												//intermediate element
				{
					newrec->next=prev->next;
					prev->next=newrec;
				}
			}

		
		return start;
	}
			//DISPLAY LINKEDLIST
/*************************<Function Header>*************************/
/*!
@fn: void *displayNode(struct node *start)
@brief ABSTRACT:

Description:  Display of linked list data 
@param:  struct node *start
@return :  start
@remarks
@warning
@see
*/
/*****************************************************************/
	void *displayNode(struct node *start)
	{
		struct node *temp;
		temp=start;
		//display list
		printf("Node element are :\n\n");
		for(temp=start;temp!=NULL;temp=temp->next)
		{
			printf("Linked list Data\t%d\n",temp->roll_no);
		}
	}

			//DISPLAY IN REVERSE
/*************************<Function Header>*************************/
/*!
@fn: void *displayNode_Reverse(struct node *start)
@brief ABSTRACT:

Description:  Display of linked list data in Reverse order
@param:  struct node *start
@return :  start
@remarks
@warning
@see
*/
/*****************************************************************/
	void *displayNode_Reverse(struct node *start)
	{
		struct node *temp;
		int rev[size],index=0,i;
		temp=start;
		for(temp=start;temp!=NULL;temp=temp->next)
		{
			rev[index]=temp->roll_no;
			index++;
		}
		printf("Linked list in Reverse\n\n");
		for(i=index-1;i>=0;i--)
		{
			printf("Linked list Data\t%d\n",rev[i]);
		}
	}
