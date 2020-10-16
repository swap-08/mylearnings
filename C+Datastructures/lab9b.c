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
//struct employee *accept(struct employee *emp,int size);
//struct employee *display(struct employee *emp,int size);
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

	//person 1
	printf("\nEnter person1 name\n");
	scanf("%s",temp_name1);		

	person1.person_name=(char *)malloc(sizeof(char)*(strlen(temp_name1)+1));
	strcpy(person1.person_name,temp_name1);
	
	printf("\nEnter Telephone Number\n");
	scanf("%d",&person1.person_phonenumber);


	////person 2
	printf("\nEnter person2 name\n");
	scanf("%s",temp_name2);		

	person2.person_name=(char *)malloc(sizeof(char)*(strlen(temp_name2)+1));
	strcpy(person2.person_name,temp_name2);
	
	printf("\nEnter Telephone Number\n");
	scanf("%d",&person2.person_phonenumber);

	printf("******Person 1 Details*******\n");

	//person 1
	printf("\n\nPerson1 name :\t%s",person1.person_name);		

	printf("\nTelephone Number :\t%d\n\n",person1.person_phonenumber);

	printf("******Person 2 Details*******\n");

	////person 2
	printf("\n\nPerson2 name :\t%s",person2.person_name);		

	printf("\nTelephone Number :\t%d\n\n",person2.person_phonenumber);
	
	free(person1.person_name);
	free(person2.person_name);
	return 0;
}