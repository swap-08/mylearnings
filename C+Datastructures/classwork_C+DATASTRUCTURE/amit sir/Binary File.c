#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<process.h>
typedef struct
{
  	int eno;
 	char n[25];
 	float sal;
}EMP;
void getemployee(EMP *t)
{
  	printf("Employee No.:%d",t->eno);
  	printf("\nEnter Employee Name:");
  	fflush(stdin);
  	gets(t->n);
  	printf("Enter Employee Salary:");
  	fflush(stdin);
  	scanf("%f",&t->sal);
}
void putemployee(EMP t)
{
 	printf("\n%d %s %.2f",t.eno,t.n,t.sal);
}
void addrecord()
{
	   FILE *fp;
	   EMP e,e1;
	   int c;
	   fp=fopen("emp.dat","ab+");
	   if(fp==NULL)
	   {
			 puts("File can't be created");
			 return;
		}
		c=0;
		rewind(fp);
		fread(&e,sizeof(e),1,fp);
		while(!feof(fp))
		{
			 c++;
			 e1=e;
			 fread(&e,sizeof(e),1,fp);
		}
		if(c==0)
			e.eno=1;
		else
			e.eno=e1.eno+1;
		getemployee(&e);
		fseek(fp,0,SEEK_END);
		fwrite(&e,sizeof(e),1,fp);
		fclose(fp);
}
void displayrecords()
{
	FILE *fp;
	EMP e;
	fp=fopen("emp.dat","rb");
	if(fp==NULL)
	{
		 puts("File can't be opened");
		 return;
	}
	fread(&e,sizeof(e),1,fp);
	while(!feof(fp))
	{
		 putemployee(e);
		 fread(&e,sizeof(e),1,fp);
	}
	fclose(fp);
}
void modifyrecord()
{
	FILE *fp;
	int c,teno;
	EMP e;
	c=0;
	fp=fopen("emp.dat","rb+");
	if(fp==NULL)
	{
		 puts("File can't be opened");
		 return;
	 }
	 puts("Enter Employee No. to Modify:");
	 scanf("%d",&teno);
	 fread(&e,sizeof(e),1,fp);
	 while(!feof(fp))
	 {
		 if(e.eno==teno)
				break;
		 fread(&e,sizeof(e),1,fp);
		 c++;
	 }
	 if(feof(fp))
	 {
		  printf("Record Not Found");
	 }
	 else
	 {
		putemployee(e);
		printf("\n Enter New Contents...\n");
		getemployee(&e);
		fseek(fp,c*sizeof(e),SEEK_SET);
		fwrite(&e,sizeof(e),1,fp);
		printf("Record Modified");
	 }
	 fclose(fp);
}
void searchrecord()
{
	 FILE *fp;
	 EMP e;
	 int teno;
	 fp=fopen("emp.dat","rb");
	 if(fp==NULL)
	 {
		 puts("File can't be opened");
		 return;
	 }
	 puts("Enter Employee No. to Search:");
	 fflush(stdin);
	 scanf("%d",&teno);
	 fread(&e,sizeof(e),1,fp);
	 while(!feof(fp))
	 {
		 if(e.eno==teno)
			break;
		 fread(&e,sizeof(e),1,fp);
	 }
	 if(feof(fp))
		  printf("Record Not Found");
	 else
		  putemployee(e);
	 fclose(fp);
}
void deleterecord()
{
	FILE *fp,*tp;
	EMP e;
	int teno,i;
	puts("Enter Employee No. to Delete:");
	fflush(stdin);
	scanf("%d",&teno);
	fp=fopen("emp.dat","rb");
	if(fp==NULL)
	{
		 puts("Operation Unsuccessful");
		 return;
	}
	tp=fopen("temp.dat","wb");
	if(tp==NULL)
	{
		 puts("Operation Unsuccessful");
		 fclose(fp);
		 return;
	}
	i=0;
	fread(&e,sizeof(e),1,fp);
	while(!feof(fp))
	{
		 if(e.eno!=teno)
			  fwrite(&e,sizeof(e),1,tp);
		 else
			  i=1;
		 fread(&e,sizeof(e),1,fp);
	}
	fcloseall();
	if(i==0)
	{
	  puts("record not Found");
	  remove("temp.dat");
	}
	else
	{
	   puts("record deleted");
	   remove("emp.dat");
	   rename("temp.dat","emp.dat");
	}
}
void sortrecords()
{
	FILE *fp;
	int i,j,c;
	EMP e,*t;
	fp=fopen("emp.dat","rb");
	if(fp==NULL)
	{
		 puts("Operation Unsuccessful");
		 return;
	}
	fseek(fp,0,SEEK_END);
	c=ftell(fp)/sizeof(e);
	t=(EMP *)malloc(c*sizeof(EMP));
	if(t==NULL)
	{
		 puts("Insufficient Memory");
		 fclose(fp);
		 return;
	}
	i=0;
	rewind(fp);
	fread(&e,sizeof(e),1,fp);
	while(!feof(fp))
	{
		t[i++]=e;
		fread(&e,sizeof(e),1,fp);
	}
	fclose(fp);
	for(i=0;i<c-1;i++)
	{
		for(j=c-1;j>i;j--)
		{
			if(strcmp(t[j].n,t[j-1].n)<0)
			{
				  e=t[j];
				  t[j]=t[j-1];
				  t[j-1]=e;
			}
		}
	}
	for(i=0;i<c;i++)
		 putemployee(t[i]);
}
void main()
{
	int ch=0;
	while(ch!=7)
	{
		system("cls");
		puts("1. Add record");
		puts("2. Display records");
		puts("3. Search record");
		puts("4. Modify record");
		puts("5. Delete record");
		puts("6. Sort records");
		puts("7. Exit");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:addrecord();
				   break;
			case 2:displayrecords();
				   break;
			case 3:searchrecord();
				   break;
			case 4:modifyrecord();
				   break;
			case 5:deleterecord();
				   break;
			case 6:sortrecords();
				   break;
		}
	}
}