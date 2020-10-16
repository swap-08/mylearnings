#include<stdio.h>
#define SIZE 5
typedef struct stack
{
	int a[SIZE];
	int top;
}STACK;
void initializestack(STACK *t)
{
	t->top=-1;
}
int stackempty(STACK *t)
{
	if(t->top==-1)
		return 1;
	else
		return 0;
}
int stackfull(STACK *t)
{
	if(t->top==SIZE-1)
		return 1;
	else
		return 0;
}
int push(STACK *t,int e)
{
	if(!stackfull(t))
	{
		t->top++;
		t->a[t->top]=e;
		return 1;
	}
	else
		return 0;
}
int pop(STACK *t,int *e)
{
	if(!stackempty(t))
	{
		*e=t->a[t->top];
		t->top--;
		return 1;
	}
	else
		return 0;
}
int peep(STACK *t)
{
	return t->a[t->top];
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
			case 1:if(!stackfull(&s))
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
}//