#include<stdio.h>
#include<malloc.h>
typedef struct data
{
	int eno;
	char n[30];
	float sal;
}DATA;
typedef struct node
{
	DATA d;
	struct node*next;
}NODE;
typedef struct list
{
	NODE*start;
	NODE*end;
}LIST;
void initializelist(LIST *t)
{
	t->start=t->end=NULL;
}
NODE *createnode()
{
	NODE*new;
	new=(NODE*)malloc(sizeof(NODE));
	return new;
}

void acceptdata(DATA *t)
{
	printf("Enter employee no.:");
	scanf("%d",&t->eno);
	printf("Enter Name:");
	fflush(stdin);
	gets(t->n);
	printf("Enter salary:");
	scanf("%f",&t->sal);
}

int listempty(LIST *t)
{
	if(t->start==NULL && t->end==NULL)
		return 1;
	else
		return 0;
}
int listfull()
{
	NODE *new;
	new=createnode();
	if(new==NULL)
		return 1;
	else
	{
		free(new);
		return 0;
	}
}
int addnodeatstart(LIST *t)
{
	NODE *new;
	if(!listfull())
	{
		new=createnode();
		acceptdata(&new->d);
		new->next=NULL;
		if(listempty(t))
			t->start=t->end=new;
		else
		{
			new->next=t->start;
			t->start=new;
		}
		return 1;
	}
	else
		return 0;
}
int addnodeatend(LIST *t)
{
	NODE *new;
	if(!listfull())
	{
		new=createnode();
		acceptdata(&new->d);
		new->next=NULL;
		if(listempty(t))
			t->start=t->end=new;
		else
		{
			t->end->next=new;
			t->end=new;
		}
		return 1;
	}
	else
		return 0;
}
void displaynodesfromstart(LIST *t)
{
	NODE *temp;
	for(temp=t->start;temp!=NULL;temp=temp->next)
		printf("\n %d %s %.2f",temp->d.eno,temp->d.n,temp->d.sal);
}
int searchnode(LIST *t,int teno)
{
	NODE *temp;
	for(temp=t->start;temp!=NULL;temp=temp->next)
	{
		if(temp->d.eno==teno)
			break;
	}
	if(temp==NULL)
	{
		printf("record not found");
		return 0;
	}
	else
	{
		printf("record found");
		printf("\n %d %s %.2f",temp->d.eno,temp->d.n,temp->d.sal);
		return 1;
	}
}
NODE *search_node(LIST *t,int teno)
{
	NODE *temp;
	for(temp=t->start;temp!=NULL;temp=temp->next)
	{
		if(temp->d.eno==teno)
			return temp;
	}
	return 0;
}
int modifynode(LIST *t,int teno)
{
	NODE *temp;
	for(temp=t->start;temp!=NULL;temp=temp->next)
	{
		if(temp->d.eno==teno)
			break;
	}
	if(temp==NULL)
	{
		printf("record not found");
		return 0;
	}
	else
	{
		printf("record found");
		printf("\n %d %s %.2f",temp->d.eno,temp->d.n,temp->d.sal);
		printf("\n enter new data...\n");
		acceptdata(&temp->d);
		printf("\n record modified");
		return 1;
	}
}
int modify_node(LIST *t,int teno)
{
	NODE *temp;
	temp=search_node(t,teno);
	if(temp==0)
		return 0;
	else
	{
		printf("record found");
		printf("\n %d %s %.2f",temp->d.eno,temp->d.n,temp->d.sal);
		printf("\n enter new data...\n");
		acceptdata(&temp->d);
		printf("\n record modified");
		return 1;
	}
}
int addnodebeforenode(LIST *t,int teno)
{
	NODE *t1,*t2,*new;
	t1=t2=t->start;
	while(t1!=NULL)
	{
		if(t1->d.eno==teno)
			break;
		t2=t1;
		t1=t1->next;
	}
	if(t1==NULL)
	{
		printf("node cannot be added");
		return 0;
	 }
	 if(!listfull())
	 {
			new=createnode();
			acceptdata(&new->d);
			new->next=NULL;
			if(t1==t->start)
			{
				new->next=t->start;
				t->start=new;
			}
			else
			{
				t2->next=new;
				new->next=t1;
			}
			return 1;
	 }
	 else
		return 0;
}
int addnodeafternode(LIST *t,int teno)
{
	NODE *t1,*new;
	t1=t->start;
	while(t1!=NULL)
	{
		if(t1->d.eno==teno)
			break;
		t1=t1->next;
	}
	if(t1==NULL)
	{
		printf("node cannot be added");
		return 0;
	 }
	 if(!listfull())
	 {
			new=createnode();
			acceptdata(&new->d);
			new->next=NULL;
			if(t1==t->end)
			{
				t->end->next=new;
				t->end=new;
			}
			else
			{
				new->next=t1->next;
				t1->next=new;
			}
			return 1;
	 }
	 else
		return 0;
}
int deletenode(LIST *t,int teno)
{
	NODE *t1,*t2;
	t1=t2=t->start;
	if(listempty(t))
		return 0;
	while(t1!=NULL)
	{
		if(t1->d.eno==teno)
			break;
		t2=t1;
		t1=t1->next;
	}
	if(t1==NULL)
	{
		printf("node to be deleted not found");
		return 0;
	 }
	 if(t1==t->start)
		t->start=t->start->next;
	 else
		if(t1==t->end)
		{
			t->end=t2;
			t->end->next=NULL;
		}
		else
			t2->next=t1->next;
	 free(t1);
	 return 1;
}
void sortnodes(LIST *t)
{
	NODE *i,*j;
	DATA x;
	for(i=t->start;i!=t->end;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
									if(i->d.eno>j->d.eno)
			{
				x=i->d;
				i->d=j->d;
				j->d=x;
			}
		}
	}
}
main()
{
	LIST L;
	int ch=0,teno;
	initializelist(&L);
	while(ch!=10)
	{
		puts("1.Add Node at start");
		puts("2.Add Node at end");
		puts("3.Add Node before node");
		puts("4.Add Node after node");
		puts("5.Display Nodes from start");
		puts("6.Search Node");
		puts("7.Modify Node");
		puts("8.Delete Node");
		puts("9.Sort Nodes");
		puts("10.Exit");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:addnodeatstart(&L);
				   break;
			case 2:addnodeatend(&L);
				   break;
			case 3:printf("Enter Employee No.:");
				   scanf("%d",&teno);
				   addnodebeforenode(&L,teno);
				   break;
			case 4:printf("Enter Employee No.:");
				   scanf("%d",&teno);
				   addnodeafternode(&L,teno);
				   break;
		   case 5: displaynodesfromstart(&L);
				   break;
		   case 6: printf("Enter Employee No. to search:");
				   scanf("%d",&teno);
				   searchnode(&L,teno);
				   break;
		   case 7: printf("Enter Employee No. to Modify:");
				   scanf("%d",&teno);
				   modifynode(&L,teno);
				   break;
		   case 8: printf("Enter Employee No. to Delete:");
				   scanf("%d",&teno);
				   deletenode(&L,teno);
				   break;
		   case 9: sortnodes(&L);
				   break;
		}
		}
}

