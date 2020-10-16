/*************************<File Header>*************************/
/*!
@file: lab8b.c
@Brief Abstract:
Description:Write a program in C which performs desired operations
@note
@todo
Author:Swapnil Kadam
Date:27/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
int main()
{
	char choice,str[30],tempstr[30];
	int size,flag=0,check;
	printf("Enter any strings\n");
	scanf("%s",str);
	do
	{
	printf("Select an Option\n a.\tReverse string\n b.\tCheck whether palindrome or not\n c.\tConvert to Lower\n d.\tConvert to Upper\n e.\tConvert to title case\n f.\tConvert to sentence case\n g.\tConvert to toggle case\n h.\tCount vowels\n i.\ty\n j.\tSearch a value in the array\n k.\tExit\n");
	fflush(stdin);
	scanf("%c",&choice);

		switch(choice)
		{
		case 'a':
			//reverse
			printf("Reverse os string :\t%s\n\n",strrev(str));
			break;
		case 'b':
			//palindrome
			check=strcmp(str,strrev(str));
			if(0==check)
				printf("STRING IS PALINDROME\n\n");
			else
				printf("STRING IS NOT A PALINDROME\n\n");						
			break;
		case 'c':
			//lowercase
			printf("String in Lower case:\t%s\n\n",strlwr(str));
			break;
		case 'd':
			//uppercase
			printf("String in Upper case:\t%s\n\n",strupr(str));
			break;
		case 'e':
			//title case
			printf("String in Title case:\t%s\n\n",strtitle(str));	
			break;
		case 'f':
			
			break;
		case 'g':
						
			break;
		case 'h':
			
			break;
		case 'i':
			
			break;
		case 'j':
			
			break;
		case 'k':
			flag=1;
			break;
		default:
			printf("\t*****INVALID CHOICE****\n");
			break;
		}
	}
	while(flag!=1);
	return 0;
}