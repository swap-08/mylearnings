#include<stdio.h>
struct node *getNode();
struct node *Push(struct node *start,struct node *newrec);
struct node *Pop(struct node *start);
void *displayStack(struct node *start);
struct node
{
	int roll_no;
	struct node *next;
};
int main()
{
	int select,flag=0;
	char ch='y';
	struct node *start=NULL,*newrec=NULL;
	do
	{
		printf("Enter your choice :\n1)\tCreate Node\n2)\tPUSH Element\n3)\tDisplay\n4)\tPOP Element\n5)\tExit\n");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				newrec=getNode();
				break;
			case 2:
				//push
				start=Push(start,newrec);
				break;
			case 3:
				displayStack(start);
				break;
			case 4:
				//pop
				if(start==NULL)
				{
					printf("Stack is empty....\n");
				}
				else
					start=Pop(start);
				break;
			case 5:
				flag=1;
				//printf("Invalid Choice\n");
				break;
		}
	}
	while(flag!=1);
	return 0;
}
	struct node *getNode()
	{
		struct node *newrec;	
		newrec=(struct node *)malloc(sizeof(struct node));
		newrec->next=NULL;
		//printf("Node Successfully created\n\n");
		return newrec;
	}
				//////////insertion
	struct node *Push(struct node *start,struct node *newrec)
	{
		struct node *temp=NULL,*prev=NULL;
		char choice='y';
		
		//addition of node
	while(choice!='n')
	{
		printf("Enter roll number\n");
		//newrec=getNode();
		newrec=(struct node *)malloc(sizeof(struct node));		
		newrec->next=NULL;//temp=start;
		if(start==NULL)
			start=newrec;
		else
			temp->next=newrec;
			scanf("%d",&newrec->roll_no);
			temp=newrec;
			//newrec->next=NULL;

		printf("do u want to add element\n(y or n)\n");
		fflush(stdin);
		scanf("%c",&choice);
	}/*
		while(choice!='n')
		{
			newrec=getNode();
			//newrec=(struct node *)malloc(sizeof(struct node));
			//newrec->next=NULL;

			printf("Enter Roll no :\n");
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

				printf("do u want to PUSH another element\n(y or n)\n");
				fflush(stdin);
				scanf("%c",&choice);
		
		}*/
		printf("Successfully PUSHED\n\n");
		return start;
	}

					//pop
	struct node *Pop(struct node *start)
	{

		struct node *prev=NULL,*temp=NULL;
		temp=start;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		if(prev==NULL)
		{
			temp->next=NULL;
			start=NULL;
		}
		else
			prev->next=NULL;
		printf("Successfully POPPED...\n\n");
		return start;
	}


		//display
	void *displayStack(struct node *start)
	{
		struct node *temp;
		temp=start;
		if(NULL==start)//display list
		{
			printf("Stack is Empty....\n\n");
		}
		else
		{
			printf("Node element are :\n\nRollnumber\n");
			for(temp=start;temp!=NULL;temp=temp->next)
			{
				printf("|%d\t",temp->roll_no);
			}
			printf("\n");
		}
	}