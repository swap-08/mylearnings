/*************************<File Header>*************************/
/*!
@file: lab8a.c
@Brief Abstract:
Description:Write a c program to encode and decode a line
@note
@todo
Author:Swapnil Kadam
Date:27/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[10];
	int i;
	printf("Enter string\n");
	scanf("%s",str);
	printf("ASCII equivalent\n");
	for(i=0;i<strlen(str);i++)
	{
		printf("%d\n",str[i]);
	}

	


	return 0;
}