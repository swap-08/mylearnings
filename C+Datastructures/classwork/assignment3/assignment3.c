#include<stdio.h>
//#include<stdlib.h>
int main()
{
	int roll_no,roll_no1;
	char name[30],name1[30],gender[5],gender1[5];
	FILE *fp1;
	printf("Enter name\n");
	scanf("%s",name);
	printf("Enter rollno\n");
	scanf("%d",&roll_no); 
	printf("Enter gender\n");
	scanf("%s",gender);

   fp1=fopen("a.txt","w");
   
   
   if( fp1 == NULL )
   {
      printf("Error while opening the file.\n");
      exit(0);
   }

	fprintf(fp1,"%s\n",name);
	fprintf(fp1,"%d\n",roll_no);
	fprintf(fp1,"%s",gender);
//	fprintf(gender,fp1);     
	printf("\nCOMPLETED");
	
	rewind(fp1);
	fclose(fp1);
	printf("\nREWIND\n");

	fp1=fopen("a.txt","r");

	fscanf(fp1,"%s",name1);
	fscanf(fp1,"%d",&roll_no1);
	fscanf(fp1,"%s",gender1);
	fclose(fp1);

	printf("name \t%s\nrollno\t%d\ngender\t%s\n",name1,roll_no1,gender1);
  	return 0;
}