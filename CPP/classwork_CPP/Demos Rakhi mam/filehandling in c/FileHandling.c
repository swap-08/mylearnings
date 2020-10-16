#include<stdio.h>
#include<conio.h>
void main(int argc,char *argv[])
{
	FILE *fp;
	char ch,ch1='N';
	int f=0;

	if(argc<2)
	{
		printf("Required parameter missing");
		return;
	}
	else
		   if(argc>2)
		   {
			   printf("Too many Parameters");
			   return;
		   }
   fp=fopen(argv[1],"r");
   if(fp==NULL)
	   f=1;
   else
   {
	   printf("\n%s exists. Do you want to overwrite[Y/N]:",argv[1]);
	   ch1=getche();
	   fclose(fp);
   }
   if(ch1=='y' || ch1=='Y' || f==1)
   {
		fp=fopen(argv[1],"w");
		if(fp==NULL)
		{
			printf("\n%s cannot be created",argv[1]);
			return;
		}
		printf("\n Enter the contents for the file...\n");
		ch=getche();
		while(ch!=26) //Ascii value of ^Z
		{
			if(ch==10)
			{
				  fputc('\n',fp);
				  printf("\n");
			}
			else
				  fputc(ch,fp);
			ch=getche();
		}
		printf("\bFile Saved");
		fclose(fp);
   }
   fp=fopen(argv[1],"r");
   if(fp==NULL)
   {
			printf("\n%s cannot be opened",argv[1]);
			return;
    }
	printf("\nContents of file %s...\n",argv[1]);
	ch=fgetc(fp);
	while(!feof(fp))
	{
		putchar(ch);
		ch=fgetc(fp);
	}
	fclose(fp);
	getch();
}