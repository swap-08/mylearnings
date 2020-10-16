#include<stdio.h>
struct node *getNode();
struct node *insertNode(struct node *start,struct node *newrec);
void *displayNode(struct node *start);
struct node
{
	int roll_no;
	struct node *next;
};
int main()
{
	int select,flag=0;
	struct node *start=NULL,*newrec=NULL;
	do
	{
		printf("Enter your choice :\n1)\tCreate Node\n2)\tInsert Element\n3)\tDisplay\n");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				newrec=getNode();
				break;
			case 2:
				start=insertNode(start,newrec);
				break;
			case 3:
				displayNode(start);
			case 4:
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
		printf("Node Successfully created\n\n");
		return newrec;
	}


	struct node *insertNode(struct node *start,struct node *newrec)
	{
		struct node *temp=NULL,*prev=NULL;
		char choice='y';
		
		//addition of node

		while(choice!='n')
		{
			newrec=(struct node *)malloc(sizeof(struct node));
			newrec->next=NULL;

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

				printf("do u want to add element\n(y or n)\n");
				fflush(stdin);
				scanf("%c",&choice);
		
		}
		printf("Insertion Successfully Completed\n\n");
		return start;
	}


	void *displayNode(struct node *start)
	{
		struct node *temp;
		temp=start;
		//display list
		printf("Node element are :\n\n");
		for(temp=start;temp!=NULL;temp=temp->next)
		{
			printf("rollnumber %d\n",temp->roll_no);
		}
	}