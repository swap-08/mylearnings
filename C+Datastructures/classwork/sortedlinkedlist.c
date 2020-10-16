#include<stdio.h>
struct node
{
	int roll_no;
	struct node *next;
};
int main()
{
	struct node *newrec,*temp=NULL,*start=NULL,*prev=NULL;
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


		//display list
	for(temp=start;temp!=NULL;temp=temp->next)
	{
		printf("rollnumber %d\n",temp->roll_no);
	}
}