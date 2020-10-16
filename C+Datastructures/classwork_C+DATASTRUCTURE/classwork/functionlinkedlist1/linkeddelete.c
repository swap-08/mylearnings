#include<stdio.h>
struct node *getNode();
struct node *insertNode(struct node *start,struct node *newrec);
struct node *deleteNode(struct node *start);
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
		printf("Enter your choice :\n1)\tCreate Node\n2)\tInsert Element\n3)\tDisplay\n4)\tDelete\n5)\tExit\n");
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
				break;
			case 4:
				start=deleteNode(start);
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
	struct node *insertNode(struct node *start,struct node *newrec)
	{
		struct node *temp=NULL,*prev=NULL;
		char choice='y';
		
		//addition of node

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

				printf("do u want to add element\n(y or n)\n");
				fflush(stdin);
				scanf("%c",&choice);
		
		}
		printf("Insertion Successfully Completed\n\n");
		return start;
	}

					//////////deletion
	struct node *deleteNode(struct node *start)
	{
		struct node *last=NULL,*pre=NULL,*post=NULL,*temp=NULL;
		int count=0,t,i,n,select,element,flag=0;
		printf("\n\nfor delete using position press 1\nfor delete using element press 2\n\n");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			last=start;
			for(i=1;i<=4;i++)
			{
				while(last->next!=NULL)
				{
				count++;
				last=last->next;
				}
			}
				
			printf("count\n%d\n",count);
			printf("Enter position want to delete \n");
			scanf("%d",&n);
					//deleting last node
			t=count+1;
			if(n==t)
			{
				last=start;
				for(i=0;i<count-1;i++)
				{
				last=last->next;
				}
				//printf("last element\t%d\n",last->roll_no);
				last->next=NULL;
			}
			else if(n!=1)		//deleting non first position
			{ 
				pre = start;
				for(i=1;i<n-1 && pre->next!=NULL;i++)
				{
				pre= pre->next;
				}
				//printf("dpre ele\t%d\n",pre->roll_no);
				 
				temp = start;
				for(i=1;i<n && temp->next!=NULL;i++)
				{
					temp = temp ->next;
				}
					//printf("current element\t%d\n",temp->roll_no);
					 
				post= start;
				for(i=1;i<n+1 && post->next!=NULL;i++)
				{
					post= post->next;
				}
					//printf("post ele\t%d\n",post->roll_no);
					pre->next=post;
			}
			else
			{
				temp=start;
				start=temp->next;
				//printf("start ele\t%d\n",start->roll_no);
				//start->next=NULL;
			}
			printf("Successfully Deleted...\n\n");
			break;
				
		
		
		
		case 2:
			printf("Enter element to be delete\n");
			scanf("%d",&element);
			temp=start;
			pre=start;
			post=start;
			if(start->roll_no==element)		//first element
			{
				start=temp->next;
				//temp->next=NULL;
				//printf("start\n%d\n",start->roll_no);
			}
			
			else
			{
				while(temp->roll_no!=element)		// || temp->next!=NULL)
				{
					flag=1;
					pre=temp;
					temp=temp->next;
					post=temp->next;
				}
				printf("Element present\n");
				if(temp->next=NULL)					//last element
					{
						pre->next=NULL;
					}
				else
					pre->next=post;					//temp->next;
					temp->next=NULL;				//intermediate
			
			}
		
		return start;
		break;
	}
}


					//////////displa
		void *displayNode(struct node *start)
	{
		struct node *temp;
		temp=start;
		//display list
		if(temp==NULL)
			printf("No records....\n");
		else
		{
			printf("Node element are :\n\n");
			for(temp=start;temp!=NULL;temp=temp->next)
			{
				printf("rollnumber %d\n",temp->roll_no);
			}
		}
	}