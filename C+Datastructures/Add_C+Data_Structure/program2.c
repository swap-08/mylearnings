/*************************<File Header>*************************/
/*!
@file: program2.c
@brief Abstract: Use of command line arguments
Description:Create a utility called wc which accepts name
of files as command line arguments and print number of characters
@note
@todo
Author: Swapnil Kadam
Date:28/11/2013
Change History:
*/
/*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 25
void main(int argc, char *argv[])			//COMMAND LINE ARGUEMENT DECLARATION
{
   char character, file_name[SIZE];

   //CREATING FILE POINTER AND VARIABLES
   FILE *fp;
   int words_count=0,newline_count=0,character_count=0;
   printf("Enter file name\n");
   fflush(stdin);
   gets(file_name);
   
   argv[0]=file_name;

   //OPENING FILE IN READ MODE
   fp=fopen(argv[0],"r"); 
    
   //FILE NOT PRESENT
   if(fp==NULL )
   {
      perror("Error while opening the file.\n");
      exit(0);
   } 
	//FILE PRESENT
   while((character=fgetc(fp))!=EOF)
   {
	  character_count++;
	  if(character==' ')
	  {
		  words_count++;
	  }
	 if(character=='\n')
	 {
	 newline_count++;
	 }
   }
   //PRINTING NUMBER OF CHARACTERS AND LINES 

	printf("\n The number of characters are %d \t",character_count);
	printf("\n The number of characters are %d \t",words_count+newline_count);
	printf("\n The number of new lines are %d \t",newline_count);
    
    fclose(fp);
	return 0;
}