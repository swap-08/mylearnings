#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   char ch,ch1, file_name[25],file_new[20];
   FILE *fp1,*fp2;
 
   printf("Enter the name of file you wish to see\n");
   gets(file_name);
   fp1=fopen(file_name,"r");
   
   
   if( fp1 == NULL )
   {
      printf("Error while opening the file.\n");
      exit(0);
   }
 
   
  printf("Enter the name of file you wish to write\n");
   gets(file_new);
   fp2 = fopen(file_new,"w"); 
   
   
   if( fp2 == NULL )
   {
      printf("Error while opening the file.\n");
      exit(0);
   }
 
   
 
 
   while( ( ch = fgetc(fp1) ) != EOF )
   {
     putc(ch,fp2);
	  // fprintf(fp2,"%c",ch);
	
   }  
	    fclose(fp2);
	fp2 = fopen(file_new,"r"); 
  while( ( ch1 = fgetc(fp2) ) != EOF )
      printf("%c",ch1);
	  printf("\nCOMPLETED");
 
   fclose(fp1);
   fclose(fp2);
   return 0;
}