#include<stdio.h>
struct node
{
	int roll_no;
	struct node *next;
};
int main()
{
	struct node *newrec,*temp=NULL,*start=NULL,*last=NULL,*pre=NULL,*post=NULL;
	char choice='y';
	int position,i,element,count=0,n,t;
	
	temp=start;
	while(choice!='n')
	{
		printf("Enter roll number\n");
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
	}



	for(temp=start;temp!=NULL;temp=temp->next)
	{
		printf("rollnumber %d\n",temp->roll_no);
	}


	//addition of node

	printf("Enter element to add the new node\n");
	scanf("%d",&element);
	printf("Enter position to add the new node\n");
	scanf("%d",&position);

	if(position!=1)				//adding to non first position
	{
		temp=start;
		for(i=1;i<position-1 && temp->next!=NULL;i++)
		{
			temp=temp->next;
		}
		//printf("rollnumber %d\nend\n",temp->roll_no);
		
		
		newrec=(struct node *)malloc(sizeof(struct node));
		newrec->roll_no=element;
		newrec->next=temp->next;
		temp->next=newrec;
	}
	else			//adding to first position
	{
		newrec=(struct node *)malloc(sizeof(struct node));
		newrec->roll_no=element;
		newrec->next=start;
		start=newrec;
	}


		//display list
	for(temp=start;temp!=NULL;temp=temp->next)
	{
		printf("rollnumber %d\n",temp->roll_no);
	}




	//deletion of node

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
			//display of list
		for(temp=start;temp!=NULL;temp=temp->next)
		{
		printf("%d\n",temp->roll_no);
		}

	return 0;
}