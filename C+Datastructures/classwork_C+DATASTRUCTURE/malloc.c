#include <stdio.h>
void display(struct employee_file *,int n);
void insert(struct employee_file *s,int n);
struct employee_file 
{
	int emp_code;
	char emp_name[30];
};

void main()
{
	int i,j=0,b,a,sum=0,n;
	int count=0;
	struct employee_file *s;

		
	printf("enter no of employee");
	scanf("%d",&n);

	s=(struct employee_file *)calloc(sizeof(struct employee_file),n);


	printf("size of s  %d",s);


	insert(s,n);


	display(s,n);
}


void insert(struct employee_file *s,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
    printf("\n enter employee name");
	scanf("%s",s->emp_name);
	printf("\nenter employee code:");
	scanf("%d",&s->emp_code);
	s++;
	}
}
void display(struct employee_file *s,int n)

{

	int i;
	for(i=0;i<n;i++)
	{

    printf("\n enter employee name  %s",s->emp_name);
	printf("\nenter employee code:  %d",s->emp_code);
	s++;
	}
}