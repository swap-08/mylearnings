/*************************<File Header>*************************/
/*!
@file: lab11c.c
@Brief Abstract:
Description:Write a program which take stwo file names from command line and
compares them character by character and displays if both are same.
@note
@todo
Author:Swapnil Kadam
Date:27/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	char filename1[30],filename2[30],ch1,ch2;
	int number,character=0,words=0,newline=0,count1=0,count2=0;
	FILE *fp1,*fp2;
		
	printf("Enter file name\n");
	scanf("%s",filename1);

	printf("Enter file name\n");
	scanf("%s",filename2);

		//open files
	fp1=fopen(filename1,"r");
	fp2=fopen(filename2,"r");
	
	if(fp1==NULL)
	{
		printf("File 1 does not exist..\n");
		return;
	}
	if(fp2==NULL)
	{
		printf("File 2 does not exist..\n");
		return;
	}

	while(1)
	{
		ch1=fgetc(fp1);
		ch2=fgetc(fp2);
		if(EOF==ch1)
		{
			printf("End of file 1..\n");
			do
			{
				printf("%c",ch2);
			}
			while(ch2!=EOF);
			return;
			//break;
		}
		if(EOF==ch2)
		{
			printf("End of file 2..\n");
			do
			{
				printf("%c",ch1);
			}
			while(ch1!=EOF);
			return;
			//break;
		}
		if(ch1==ch2)
		{
			count1++;
			printf("character %c of file1 matches %c of file2 at location\n\n",ch1,ch2,count1+1);
		}
		if(ch1!=ch2)
		{
			count2++;
			printf("character %c of file1 mismatches %c of file2 at location\n\n",ch1,ch2,count2+1);
		}

	}
	fclose(fp1);
	fclose(fp2);
}