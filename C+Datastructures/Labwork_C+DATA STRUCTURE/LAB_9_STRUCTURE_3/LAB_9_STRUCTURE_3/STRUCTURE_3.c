#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


	struct directory
	{
		char name[20];
		int phone_number;

	};


	void main()
	{	
		int i,size;
		struct directory *person[50];


		
		printf("Enter The Size Of the Structure\n ");
		fflush(stdin);
		scanf("%d",&size);

		for(i=0;i<size;i++)
		{
		person[i]=(struct directory *)malloc(sizeof(struct directory));

		printf("Enter The Person Name\n ");
		fflush(stdin);
		scanf("%s",person[i]->name);
		printf("Enter The Telephone No.\t ");
		fflush(stdin);
		scanf("%d",&person[i]->phone_number);
		}


		for(i=0;i<size;i++)
		{
		printf("The Person Name");
		puts(person[i]->name);
		printf("\n The Telephone No. : %d\n",person[i]->phone_number);
	
		}

		for(i=0;i<size;i++)
		{
			free(person[i]);
		}
		
	
	}