#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{

	FILE *fp1,*fp2;
	char ch1,ch2;
	int count=0;
	int count1=0;
	int count2=0;
	int flag=0;

	fp1=fopen("file1.txt","r");
	fp2=fopen("file2.txt","r");

		if(fp1==NULL || fp2==NULL)
	{
		printf("Error While Opening File");
		exit(0);
	}
		else
		{
			while(1)
			{
				ch1=getc(fp1);
				ch2=getc(fp2);


	if((ch1==EOF)&&(ch2!=EOF))
	{
		printf("ERROR in EOF of FILE 1");
		printf("%d",count1);
		printf("EOF FILE 1 %d",ftell(fp1));
		count1=count1-1;
	

	}
	else
		if((ch1!=EOF)&&(ch2==EOF))
	{
		printf("ERROR in EOF of FILE 2");
		printf("EOF FILE 1 %d",ftell(fp2));
		printf("%d",count2);
		count2=count2-1;
		
	}
		else
			if((ch1==EOF)&&(ch2==EOF))
			{ 
				break;
			}
			else if(ch1==ch2)
			{
				count1++;
				count2++;
				flag=1;

				printf("SAME %c \n",ch1);
				
			}
			else if(ch1!=ch2)
			{	flag=2;
				printf("\nFILE 1 %d",ftell(fp1));
				printf("\nFILE 2 %d",ftell(fp2));
				//printf("%d",count1);
				printf("\nFILE 1 CHAR %c",ch1);
				printf("\nFILE 2 CHAR %c",ch2);
				break;
			}
		
			}


			
		}

		if(flag==1 && count1==count2)
		printf("\n Both files are same");
		else if(flag==2)
		printf("\n Both files NOT are same");


		fclose(fp1);
		fclose(fp2);

		getch();

}