#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp;
	char ch,ch1;
	int f=0;

	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
		f=1;
	}
	else
	{
		printf("a.txt exists. Do you want to overwrite[Y/N]:");
		ch1=getche();
		fclose(fp);
	}
	if(ch1=='y' || ch1=='Y' || f==1)
	{
		fp=fopen("a.txt","w");
		if(fp==NULL)
		{
			printf("File cannot be created");
			return;
		}
		printf("Enter contents for a.txt...\n");
		ch=getche();
		while(ch!=26) //Ascii value of ^Z
		{
			if(ch==13) //Ascii value of Enter Key
			{
				printf("\n");
				fputc('\n',fp);
			}
			else
				fputc(ch,fp);
			ch=getche();
		}
		printf("\b^Z\n1 File created");
		fclose(fp);
	}
	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
		printf("File does not exist");
		return;
	}
	printf("\nContents of a.txt...\n");
	ch=fgetc(fp);
	while(!feof(fp))
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
}