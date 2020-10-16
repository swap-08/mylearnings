#include<stdio.h>
struct node
{
	char c;
	struct node *next;
};




	struct node *create(struct node *head,char ch)
	{
	struct node *newRecord,*temp;
	
	newRecord=(struct node *)malloc(sizeof(struct node));
	newRecord->c=ch;
	newRecord->next=NULL;
	temp=head;

	if(head==NULL)
		head=newRecord;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=newRecord;
	}

	return head;
	}

	void display(struct node *head)
	{
	struct node *temp;
	
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%c",temp->c);
	}
	}

	void reconstruct(struct node *head)
	{
		char construct[100];
		int i=0;
		struct node *temp;
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			construct[i]=temp->c;
			i++;
		}
		construct[i]='\0';
	
		printf("\n Reconstructed string is \t ");
		printf("%s",construct);
	}
		void main()
		{
		int i;
		char string[100];
		struct node *head=NULL;

		printf("Enter the string \t ");
		gets(string);
		for(i=0;i<strlen(string);i++)
		{
			head=create(head,string[i]);
		}
		
		
		printf("The Display of Link LIST \t ");

		display(head);


		reconstruct(head);


		getch();
		}



