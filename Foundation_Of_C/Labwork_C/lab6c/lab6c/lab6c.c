#include<stdio.h>
int main()
{
	char ch,str[40];
	int i,count=0,len;
	printf("Enter any character string\n");
	scanf("%s",str);
	len=strlen(str);
	fflush(stdin);
	printf("Enter character to be search\n");
	scanf("%c",&ch);

	for(i=0;i<len;i++)
	{
		if(str[i]==ch)
		{
			count++;
		}
	}
	if(count==0)
		printf("Character not present\n\n");
	else
		printf("Number of occurence   :%d\n\n",count);
}