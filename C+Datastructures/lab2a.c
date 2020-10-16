/*************************<File Header>****************************/
/*!
@file: lab2a.c
@Brief Abstract:
Description:Write a program that invert s the bits of unsigned char x and stores answer in y
@note
@todo
Author:Swapnil Kadam
Date:22/11/2013
Change History: None
*/
/*****************************************************************/
#include<stdio.h>
	//function prototype
void dectobinary(int dec,int *temp);
void invert(int dec,int *temp);

int main()
{
	int dec,i=0,tmp[8]={0,0,0,0,0,0,0,0};
	printf("Enter any Decimal Number\n");
	scanf("%d",&dec);
	dectobinary(dec,tmp);
	invert(dec,tmp);
}

	//function to convert decimal into binary 
void dectobinary(int dec,int *temp)
{	
	int i=0;
	while(dec!=0)
	{
		
		temp[i]=dec%2;
		i++;
		dec=dec/2;
	}
	printf("\n\nBinary of specified digit\n");
	
	for(i=7;i>=0;i--)
	{
		printf("%d",temp[i]);
	}
}
	//function to invert binary digit 
void invert(int dec,int *temp)
{	
	int i;
	printf("\n\nInverted binary digit\n");
	
	for(i=7;i>=0;i--)
	{
		if(0==temp[i])
		printf("%d",1);
		else
		printf("%d",0);
	}
	printf("\n");
}