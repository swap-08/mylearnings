#include<stdio.h>
#include<conio.h>
struct student
{
	char name[40];
	int rollno;
	char gender;
};
int main()
{
	int i,j,k;
	
	struct student s1[3];
	for(i=0;i<3;i++)
	{
	fflush(stdin);
	printf("Enter Name\n");
	gets(s1[i].name);
	printf("Enter Roll number\n");
	scanf("%d",&s1[i].rollno);
	fflush(stdin);
	printf("Enter Gender\n");
	scanf("%c",&s1[i].gender);
	}
	for (j=0;j<2;j++)
	{
		for (k=0;k<2;k++)
		{
			for(i=0;i<40;i++)
			{
				if(s1[k].name[i]>s1[k+1].name[i])
				{
					struct student temp;
					temp=s1[k];
					s1[k]=s1[k+1];
					s1[k+1]=temp;
				}
			}
		}
	}

	for(i=0;i<3;i++)
		{
			printf("\n\nName : %s\n",s1[i].name);
			printf("Roll number : %d\n",s1[i].rollno);
			printf("Gender : %c\n",s1[i].gender);
		}
}