/*************************<File Header>*************************/
/*!
@file: lab9a.c
@Brief Abstract:
Description:Define a structure to represent an employee record
containing details
@note
@todo
Author:Swapnil Kadam
Date:27/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#include<string.h>
struct employee *accept(struct employee *emp,int size);
struct employee *display(struct employee *emp,int size);
struct employee
{
	int employee_id;
	char *employee_name;
	float employee_salary;
};
int main()
{
	int size,i;
	struct employee emp;
	char temp_name[10];
	printf("Enter number of employee\n");
	scanf("%d",&size);
		
	for(i=0;i<size;i++)
	{
		printf("Enter employee ID\n");
		scanf("%d",&emp.employee_id);
		printf("Enter employee name\n");
		scanf("%s",temp_name);
		
				//malloc employee name pointer
		emp.employee_name=(char *)malloc(sizeof(char)*(strlen(temp_name)+1));
		strcpy(emp.employee_name,temp_name);

		printf("\nEnter employee salary\n");
		scanf("%f",&emp.employee_salary);
	}

	printf("******Employee Details*******\n");
	
	for(i=0;i<size;i++)
	{
		printf("\n\nEmployee ID\t%d\n",emp.employee_id);
		puts(emp.employee_name);
		//printf("Employee name\t%s\n",emp.employee_name);
		printf("Employee salary\t%0.2f\n",emp.employee_salary);
	}


	free(emp.employee_name);
}