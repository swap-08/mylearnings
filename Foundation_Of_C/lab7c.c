#include<stdio.h>
int main()
{
	char str1[50],str2[50],str3[50];
	int temp;
	printf("Enter first string\n");
	gets(str1);
	printf("Enter second string\n");
	gets(str2);
		//comparing two string
	temp=strcmp(str1,str2);
	if(temp==0)
	printf("Entered strings are same\n\n");
	else
	{
		printf("Entered strings are not same\n\n");
	}

		//copying strings
	strcpy(str3,str1);
	printf("Copy of first string %s \n\n",str3);
	strcat(str1,str2);
	printf("Concatination of two string %s \n",str1);
	return 0;
}