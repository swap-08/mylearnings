/*************************<File Header>*************************/
/*!
@file: lab7a.c
@Brief Abstract:
Description:Make a file which contains the functions to 
perform the following
a. Accept an array
b. Display an array...
@note
@todo
Author:Swapnil Kadam
Date:23/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#include"HEADACCEPT.H"
int main()
{
	char choice;
	int *a;
	int size,flag=0;
	do
	{
	printf("Select an Option\n a.\tAccept an array\n b.\tDisplay an array\n c.\tSort array\n d.\tReverse array\n e.\tCount odd\n f.\tCount even\n g.\tCount Prime\n h.\tMaximum value in the array\n i.\tMinimum value in the array\n j.\tSearch a value in the array\n k.\tExit\n");
	fflush(stdin);
	scanf("%c",&choice);

		switch(choice)
		{
		case 'a':
			//accept
			printf("Enter number of array elements\n");
			scanf("%d",&size);
			a=accept(size);
			//printf("aaaa :%d",a);
			break;
		case 'b':
			//display
			display(a,size);			
			break;
		case 'c':
			sort_array(a,size);			
			break;
		case 'd':
			reverse_array(a,size);			
			break;
		case 'e':
			count_odd(a,size);			
			break;
		case 'f':
			count_even(a,size);
			break;
		case 'g':
			count_prime(a,size);			
			break;
		case 'h':
			count_maximum(a,size);
			break;
		case 'i':
			count_minimum(a,size);
			break;
		case 'j':
			search_value(a,size);
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

