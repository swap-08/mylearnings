#include<stdio.h>
int main()
{
	int i,j=0,len;
	char str[80],rev[80];
	printf("Enter any string\n");
	gets(str);
	len=strlen(str);
	if(len>80)
	{
		printf("Entered array exceeds 80 characters\n");
	}
	else
	{
		printf("String length  %d \n",len);
		printf("Entered string  %s \n",str);
	for(i=(len-1);i>=0;i--)
	{
		rev[j++]=(str[i])-32;
		
	}
	for(i=0;i<len;i++)
	{
		printf("Reverse string in capital letters  : \n");  
		for(i=0;i<len;i++)
		printf("%c",rev[i]);
		printf("\n");
	}
	}
}