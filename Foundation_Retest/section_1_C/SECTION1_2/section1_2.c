/*************************<File Header>*************************/
/*!
@file: section1_2.c
@brief Abstract: Use of File Handling
Description: Write a C program to read the data from thre file and
print the same in reverse order by elimination the spaces

Author: Swapnil Kadam
Date:28/11/2013
Change History: None
*/
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	/*VARIABLE DECLARATION*/
   char ch, file_name[25],str[25],temp[25];
   int i,j=0;


 
   /*FILE POINTER CREATED*/
   FILE *fp1,*fp2;
 

   /*GET FILE NAME FROM USER*/
   printf("Enter the name of file you wish to see\n");
   gets(file_name);
 
   /*OPEN FILE IN READ MODE*/
   fp1= fopen(file_name,"r"); 
 
   /*CHECKING FOR ERRORS IN FILE I.E FILE PRESENT OR NOT*/
   if(fp1==NULL)
   {
      printf("Error while opening the file.\n");
      exit(0);
   }
 

   /*PRINTING CONTENT OF FILE*/
   printf("The contents of %s file are :\n", file_name);

   fscanf(fp1,"\%s",str);				//getting string from file

   printf("\%s",str);					//printing the string in command prompt

   fclose(fp1);							//closing a file

	/*-------------------------------------------------------------------------*/
   /*OPEN FILE IN WRITE MODE*/
   fp2= fopen(file_name,"w");

   /*REVERSING A STRING*/
   for(i=strlen(str)-1;i>=0;i--)
   {
	   temp[j]=str[i];
	   j++;
   }
   temp[j]='\0';			//appending null character


   /*PRINTING REVERSE OF STRING IN FILE*/
   fprintf(fp2,"\%s",temp);

   fclose(fp2);				//closing a file

	 return 0;				//return with successful execution
}