#include<stdio.h>
int main()
{
	char str[9],strcopy[9],newstr[9],strcon[18];
	int i=0,j=0,count=0,count1=0,count3=0;
	printf("Enter characters\n");
	scanf("%[^\n]",str);
	for(i=0;i<9;i++)
	{
		
		if(str[i]=='\0')
		break;
		count++;
	}
printf("\nlength\n%d",count);
//copy

	for(i=0;i<=count;i++)
	{
		strcopy[i]=str[i];
	}
	printf("\n copied string %s\n",strcopy);
	
//concatination

	printf("\nEnter characters\n");
	scanf("%s",newstr);

	for(i=0;i<9;i++)
	{

		if(newstr[i]=='\0')
		break;
		count1++;
	}
printf("length\n%d",count1);
	for(i=0;i<=count;i++)
	{
		strcon[i]=str[i];
	}
	for(i=count;i<count+count1+2;i++)
	{
		strcon[i]=newstr[j++];
	}
/*	for(i=0;i<18;i++)
	{
		count3++;
		if(strcon[i]=='\0')
		break;
	}

printf("\lrngth\n%d",count3);
*/
	printf("\nconcatenated string\n%s\n",strcon);
}
	