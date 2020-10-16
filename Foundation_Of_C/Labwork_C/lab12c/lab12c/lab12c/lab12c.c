#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   char ch, file_name[25];
   FILE *fp;
   int space=0,tab=0,new=0;
 
  
 
   fp = fopen("two.txt","r"); 
 
   if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(0);
   }
 
  
 
   while( ( ch = fgetc(fp) ) != EOF )
   {
     if(ch==' ')
	 {
	 space++;
	 
	 }
	  else if(ch=='\n')
	 {
	 new++;
	 
	 }
	 else if(ch=='\t')
	 {
	 tab++;
	 
	 }
	 
    
  }
  
  printf("\n The number of spaces are %d \t",space);
  printf("\n The number of tabs are %d \t",tab);
  printf("\n The number of new lines are %d \t",new);
  
  
    fclose(fp);
   return 0;
}