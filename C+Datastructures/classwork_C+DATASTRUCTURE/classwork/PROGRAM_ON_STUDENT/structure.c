/*wap to create a structure called student having name,rollno,num of matches played,highest score,gender
create a menu driven prog to 
1) ADD STUDENT
2) DISPLAY STUDENT
3) SORT THE STUDENT ON BASED OS NAME
4)                              ROLLNO



(
``FOR MENU USED SWITCH CASE
``FOR OPTIONS USE FUNCTION
FOR SORTING USE BUBBLESORT
ARRAY OF STRUCTURE SHOULD BE LOCAL VARIABLE OF MAIN
) */

#include <stdio.h>
#include<string.h>
//#define MAX=30;
struct student
{
	char name[30],gender[10];
	int rollno,num_matches,high_score;
};

		/*function prototype*/

void adddetails(struct student *stud,int num);
void displaydetails(struct student *stud,int num);
void sortname(struct student *stud,int num);
void sortrollno(struct student *stud,int num);

void adddetails(struct student *stud,int num)
{
	int i;
	i=num;
	//for(i=0;i<num;i++)
	//{
		printf("Enter name of student\n");
		fflush(stdin);
		scanf("%s",stud[i].name);
		printf("Enter roll number of student\n");
		scanf("%d",&stud[i].rollno);
		printf("Enter  number of matches played by the student\n");
		scanf("%d",&stud[i].num_matches);
		printf("Enter highest score of student\n");
		scanf("%d",&stud[i].high_score);
		printf("Enter gender of student\n");
		fflush(stdin);
		scanf("%s",&stud[i].gender);
	//}
	printf("Successfully Entered all the details\n\n");
}

void displaydetails(struct student *stud,int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("Name of student\t%s\n",stud[i].name);
		printf("Roll number of student\t%d\n",stud[i].rollno);
		printf("Number of matches played by the student\t%d\n",stud[i].num_matches);
		printf("Highest score of student\t%d\n",stud[i].high_score);
		printf("Gender of student\t%s\n",&stud[i].gender);
	}
		printf("Successfully displayed all the details\n\n");
}

void sortname(struct student *stud,int num)
{
	int i,j;
	struct student temp;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1;j++)
		{
			if((strcmp(stud[i].name,stud[i+1].name))>0)
			{
				temp=stud[i];
				stud[i]=stud[i+1];
				stud[i+1]=temp;
			}
		}
	}
	printf("\n\n\t....SORTING COMPLETE.....\n\n");
}


void sortrollno(struct student *stud,int num)
{
	int i,j;
	struct student temp;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1;j++)
		{
			if(stud[i].rollno > stud[i+1].rollno)
			{
				temp=stud[i];
				stud[i]=stud[i+1];
				stud[i+1]=temp;
			}
		}
	}
	printf("\n\n\t....SORTING COMPLETE.....\n\n");
}


int main()
{
	int ch,i,flag=0,num=0;
	struct student s[30];
	do
	{
		printf("Enter your choice\n1.\tADD DETAILS\n2.\tDISPLAY DETAILS\n3.\tVIEW DETAILS IN SORTED ORDER OF NAME\n4.\tVIEW DETAILS IN SORTED ORDER OF ROLL NUMBER\n5.\tEXIT\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			num++;
			adddetails(s,num);
			break;
		case 2:
			displaydetails(s,num);
			break;
		case 3:
			sortname(s,num);
			break;
		case 4:
			sortrollno(s,num);
			break;
		case 5:
			flag=1;
			break;
		default:
			printf("Invalid choice");
			break;
		}
	}
		while(flag!=1);
}