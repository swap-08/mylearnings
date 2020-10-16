/*************************<File Header>*************************/
/*!
@file: lab9b.c
@Brief Abstract:
Description:Define a structure to represent an telephone record
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
struct telephone_book
{

	char *person_name;
	int person_phonenumber;
};
int main()
{
	int size,i;
	struct telephone_book person1;
	struct telephone_book person2;
	char temp_name1[10];
	char temp_name2[10];
	printf("Enter number of telephone_book\n");
	scanf("%d",&size);
	emp=(int *)malloc(sizeof(*emp)*size);
	
	for(i=0;i<size;i++)
	{
		printf("Enter persons name\n");
		scanf("%d",&person.telephone_book_id);
		printf("Enter person name\n");
		scanf("%s",temp_name);
		
		
		
		person.person_name=(char *)malloc(sizeof(char)*(strlen(temp_name)+1));
		strcpy(person.person_name,temp_name);

		//puts(emp.person_name);




		//scanf("%s",emp->person_name);
		printf("\nEnter Telephone Number\n");
		scanf("%d",&person.person_phonenumber);
	}

	printf("******Employee Details*******\n");
	
	//for(i=0;i<size;i++)
	//{
		printf("\n\nEmployee ID\t%d\n",person.telephone_book_id);
		puts(person.person_name);
		//printf("Employee name\t%s\n",emp.employee_name);
		printf("Employee salary\t%0.2f\n",person.telephone_book_salary);
	//}


	free(person.telephone_book_name);
}






	/*printf("Enter name of employee\n");
	scanf("%s",temp_name);

	
	name=(char *)malloc(sizeof(char)*(strlen(temp_name)+1));
	name=temp_name;
	puts(name);

	printf("malloic name\n");
	puts(name);
	free(emp->employee_name);
	printf("malloic name\n");
	puts(name);
	
	
	emp=accept(emp,size,name);
	emp=display(emp,size);
}
struct employee *accept(struct employee *emp,int size,char *name)
{
	int i;

	return emp;
}

struct employee *display(struct employee *emp,int size)
{
	int i;

	return emp;
}*/