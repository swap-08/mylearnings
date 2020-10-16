#include<stdio.h>
#define MAX 5
typedef struct
{
	int a[MAX];
	int front,rear,count;
}QUEUE;
void initializequeue(QUEUE *t)
{
	t->front=t->rear=t->count=0;
}
int queueempty(QUEUE *t)
{
	if(t->count==0)
		return 1;
	else
		return 0;
}
int queuefull(QUEUE *t)
{
	if(t->count==MAX)
		return 1;
	else
		return 0;
}
int addelement(QUEUE *t,int e)
{
	if(!queuefull(t))
	{
		t->a[t->rear]=e;
		t->rear=(t->rear+1)%MAX;
		t->count++;
		return 1;
	}
	else
		return 0;
}
int removeelement(QUEUE *t,int *e)
{
	if(!queueempty(t))
	{
		*e=t->a[t->front];
		t->front=(t->front+1)%MAX;
		t->count--;
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
			case 1:if(!queuefull(&Q))
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