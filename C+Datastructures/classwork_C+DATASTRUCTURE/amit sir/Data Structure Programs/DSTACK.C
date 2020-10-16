#include<stdio.h>
typedef struct node
{
	struct node *prev;
	int a;
	struct node *next;
}NODE;
typedef struct stack
{
	NODE *top;
}STACK;
void initializestack(STACK *t)
{
	t->top=NULL;
}
int stackempty(STACK *t)
{
	if(t->top==NULL)
		return 1;
	else
		return 0;
}
int stackfull()
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
int push(STACK *t,int e)
{
	NODE *new;
	if(!stackfull())
	{
		new=(NODE*)malloc(sizeof(NODE));
		new->prev=new->next=NULL;
		new->a=e;
		if(t->top==NULL)
			t->top=new;
		else
		{
			t->top->next=new;
			new->prev=t->top;
			t->top=new;
		}
		return 1;
	}
	else
		return 0;
}
int pop(STACK *t,int *e)
{
	NODE *temp;
	if(!stackempty(t))
	{
		temp=t->top;
		*e=t->top->a;
		t->top=t->top->prev;
		if(t->top!=NULL)
			t->top->next=NULL;
		free(temp);
		return 1;
	}
	else
		return 0;
}
int peep(STACK *t)
{
	return t->top->a;
}
main()
{
	STACK s;
	int e,ch=0;
	initializestack(&s);
	while(ch!=4)
	{
		clrscr();
		puts("1.push");
		puts("2.pop");
		puts("3.peep");
		puts("4.exit");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(!stackfull())
				   {
						printf("enter element to add:");
						scanf("%d",&e);
						push(&s,e);
					}
					else
						printf("stack is full");
					break;
			case 2:if(!stackempty(&s))
					{
						pop(&s,&e);
						printf("deleted element=%d",e);
					}
					else
						printf("stack is empty");
					break;
			case 3:printf("top element=%d",peep(&s));
				   break;
		}
		getch();
	}
}


