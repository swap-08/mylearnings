#include<stdio.h>
#include<conio.h>
struct student
{
	char name[40];
	int rollno;
	int marks[5];
	char gender;
};
int main()
{
	int i;
	struct student s1;
	printf("Enter Name\n");
	scanf("%s",&s1.name);
	printf("Enter Roll number\n");
	scanf("%d",&s1.rollno);
	fflush(stdin);
	printf("Enter Gender\n");
	scanf("%c",&s1.gender);
	printf("Enter marks of 5 subjects\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&s1.marks[i]);
	}
	printf("\n\nName : %s\n",s1.name);
	printf("Roll number : %d\n",s1.rollno);
	printf("Gender : %c\n",s1.gender);
	for(i=0;i<5;i++)
	{
		printf("Marks of subject %d : %d\n",i+1,s1.marks[i]);
	}
}