#include<stdio.h>
typedef struct node
{
	struct node *prev;
	int a;
	struct node *next;
}NODE;
typedef struct queue
{
	NODE *front;
	NODE *rear;
}QUEUE;
void initializequeue(QUEUE *t)
{
	t->front=t->rear=NULL;
}
int queueempty(QUEUE *t)
{
	if(t->front==NULL && t->rear==NULL)
		return 1;
	else
		return 0;
}
int queuefull()
{
	NODE *new;
	new=(NODE*)malloc(sizeof(NODE));
	if(new==NULL)
		return 1;
	else
	{
		free(new);
		return 0;
	}
}
int addelement(QUEUE *t,int e)
{
	NODE *new;
	if(!queuefull())
	{
		new=(NODE*)malloc(sizeof(NODE));
		new->prev=new->next=NULL;
		new->a=e;
		if(queueempty(t))
			t->front=t->rear=new;
		else
		{
			t->rear->next=new;
			new->prev=t->rear;
			t->rear=new;
		}
		return 1;
	}
	else
		return 0;
}
int removeelement(QUEUE *t,int *e)
{
	NODE *temp;
	if(!queueempty(t))
	{
		*e=t->front->a;
		temp=t->front;
		t->front=t->front->next;
		if(t->front==NULL)
			t->rear=NULL;
		else
			t->front->prev=NULL;
		free(temp);
		return 1;
	}
	else
		return 0;
}
main()
{
	QUEUE Q;
	int ch=0,e;
	initializequeue(&Q);
	while(ch!=3)
	{
		clrscr();
		puts("1.add element");
		puts("2.remove element");
		puts("3.exit");
		printf("enter your choice:");
		scanf("%d",& ch);
		switch(ch)
		{
			case 1:if(!queuefull())
				   {
						printf("enter element:");
						scanf("%d",&e);
						addelement(&Q,e);
				   }
				   else
						printf("queue is full");
				   break;
			case 2:if(!queueempty(&Q))
				   {
						removeelement(&Q,&e);
						printf("deleted element=%d",e);
				   }
				   else
						printf("queue is empty");
				   break;
		}
	getch();

}
}


