/*************************<File Header>*************************/
/*!
@file: lab11b.c
@Brief Abstract:
Description:Create an utility which takes a file name as input
from user at command line and count the no. of characters,
words and lines and displays them
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
	char filename[30],ch;
	int number,character=0,words=0,newline=0;
	FILE *fp;
		
	printf("Enter file name\n");
	scanf("%s",filename);
		
		//open files
	fp=fopen(filename,"r");

	if(fp==NULL)
	{
		printf("File does not exist..\n");
		return;
	}
   while((ch=fgetc(fp))!=EOF)
   {
	   character++;

		if(ch==' ' || ch=='\n')
		{
			words++;
		}
		if(ch=='\n')
		{
			 newline++;
		}
   }
	printf("Number of characters :\t%d\n",character);
	printf("Number of words :\t%d\n",words+newline);
	printf("Number of newline :\t%d\n",newline);
	printf("Successfully completed file operation\n\n");
}