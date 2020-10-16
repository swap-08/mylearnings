/*************************<File Header>*************************/
/*!
@file: lab11a.c
@Brief Abstract:
Description:Write a program whichconsists of only numbers.if number is even
write in separate file.if number is odd write in different file.
@note
@todo
Author:Swapnil Kadam
Date:27/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char filename[30];
	int number;
	FILE *fp1,*fpeven,*fpodd;
		
		//open files
	fp1=fopen("file.txt","r");
	fpeven=fopen("even.txt","w");
	fpodd=fopen("odd.txt","w");

	if(fp1==NULL)
	{
		printf("File does not exist..\n");
		return;
	}
	if(fpeven==NULL)
	{
		printf("File does not exist..\n");
		return;
	}
	if(fpodd==NULL)
	{
		printf("File does not exist..\n");
		return;
	}

	while(!feof(fp1))
	{
		fscanf(fp1,"%d",&number);
		if(0==number%2)
			fprintf(fpeven,"%d\t",number);
		else
			fprintf(fpodd,"%d\t",number);
	}
	printf("Successfully copied numbers in even and odd files\n");
	return 0;
}