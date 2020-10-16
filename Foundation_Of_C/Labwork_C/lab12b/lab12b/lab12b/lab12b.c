
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
   char ch, file_name[25];
   FILE *fp;
 
   printf("Enter the name of file you wish to see\n");
   gets(file_name);
 
   fp = fopen(file_name,"r"); 
 
   if( fp == NULL )
   {
      printf("Error while opening the file.\n");
      exit(0);
   }
 
   printf("The contents of %s file are :\n", file_name);
 
   while( ( ch = fgetc(fp) ) != EOF )
      printf("%c",toupper(ch));
 
   fclose(fp);
   return 0;
}