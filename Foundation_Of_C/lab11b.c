#include<stdio.h>
struct telephone_book
{
	int tel_no;
	char name[20];
	struct dob
	{
		int dd,mm,yyyy;
	}bday;
};
int main()
{
	int num,i,ch,flag=0;
	struct telephone_book v[50];
	printf("Enter number of entries\n");fflush(stdin);
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("\n\nEnter name of your friend :\n");fflush(stdin);
		scanf("%s",v[i].name);
		printf("Enter telephone number :\n");
		scanf("%d",&v[i].tel_no);
		printf("Enter date of birth:\n");
		printf("Enter day of birth:\n");
		scanf("%d",&v[i].bday.dd);
		printf("Enter month of birth:\n");
		scanf("%d",&v[i].bday.mm);
		printf("Enter year of birth:\n");
		scanf("%d",&v[i].bday.yyyy);
	}
	do
	{
		printf("\n********************************************\nPress 1: to add entry :\nPress 2: to display entries :\nPress 3: to exit \n*****************************************\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			for(i=num;i<num+1;i++)
			{
				printf("\n\nEnter name of your friend :\n");fflush(stdin);
				scanf("%s",v[i].name);
				printf("Enter telephone number :\n");
				scanf("%d",&v[i].tel_no);
				printf("Enter date of birth:\n");
				printf("Enter day of birth:\n");
				scanf("%d",&v[i].bday.dd);
				printf("Enter month of birth:\n");
				scanf("%d",&v[i].bday.mm);
				printf("Enter year of birth:\n");
				scanf("%d",&v[i].bday.yyyy);
			}
			num=num+1;
			break;
		case 2:
			for(i=0;i<num;i++)
			{
				printf("\n\nNAME\t%s",v[i].name);
				printf("\nTelephone number :\t%d",v[i].tel_no);
				printf("\nDate of birth:\t%d",v[i].bday.dd);
				printf("/%d",v[i].bday.mm);
				printf("/%d",v[i].bday.yyyy);
			}
			break;
		case 3:
			flag=1;
			break;
		}
	}
	while(flag!=1);
}