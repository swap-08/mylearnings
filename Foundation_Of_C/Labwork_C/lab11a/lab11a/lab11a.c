#include<stdio.h>
struct video_cassete
{
	int srno,avail,total;
	char title[25];
};
int main()
{
	int num,i,j=0,n1,ch,total,nsr,newsrno,newavail,newtotal,flag=0,cmp,count=0;
	char name[25];
	char newtitle[25];

	struct video_cassete v[50];
	struct video_cassete wait[50];
	printf("Enter number of entries\n");fflush(stdin);
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("\n\nEnter serial no :\n");fflush(stdin);
		scanf("%d",&v[i].srno);
		printf("Enter title name :\n");
		fflush(stdin);
		scanf("%s",v[i].title);
		printf("Enter available number :\n");fflush(stdin);
		scanf("%d",&v[i].avail);
		printf("Enter total no of cassetes :\n");fflush(stdin);
		scanf("%d",&v[i].total);
	}
	do
	{
		printf("\n********************************************\nPress 1: to Issues cassette :\nPress 2: to Return cassette :\nPress 3: to See waiting list :\nPress 4: to update list of cassetes\nPress 5: to exit \n*****************************************\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter title name of cassette to be issued\n");
			fflush(stdin);
			gets(name);
			for(i=0;i<num;i++)
			{
				cmp=strcmp(v[i].title,name);
				if(cmp!=0)
				{
					printf("cassete not present\n");
					
					break;
				}
				if(v[i].avail==0)
				{
					printf("cassete not available\n\n\n");
					wait[j]=v[i];
					j++;
					count++;
					break;
				}
				else
					printf("cassete present in library   :\n\n");
					printf("Available book  : %d\n",v[i].avail);
					printf("Total number of books  : %d\n",v[i].total);
					printf("\n\n Do u want to issue :\n 1: YES \t 2: NO\n");
					scanf("%d",&n1);
					if(n1==1)
					{
						printf("cassete issued \n");
						v[i].avail=-1;
						break;
					}
					
					else
						break;
					break;
			}
			break;
			//issueofcassette();
		case 2:
			printf("Enter name of cassette to be returned\n");
			fflush(stdin);
			gets(name);
			for(i=0;i<num;i++)
			{
				if(strcmp(v[i].title,name)!=0)
				{
					printf("incorrect cassete\n");
					break;
				}
				else
				{
					v[i].avail+=1;
					printf("Cassette accepted\n");
					break;
				}
			}
			break;
			//returnofcassette();
		case 3:
			printf("Waiting list of cassettes\n\n");
			for(i=0;i<count;i++)
			{
			    printf("Serial no :%d\n",wait[i].srno);
				printf("Title name :%s\n",wait[i].title);
				printf("Available number :%d\n",wait[i].avail);
				printf("Total no of cassetes :%d\n",wait[i].total);		
			}
			break;
			//waitinglist()
		case 4:
		printf("Enter serial no for which entries to be updated :\n");fflush(stdin);
		scanf("%d",&nsr);
		for(i=0;i<num;i++)
			if(v[i].srno==nsr)
			{
				printf("Enter new serial no :\n");fflush(stdin);
				scanf("%d",&newsrno);
				v[i].srno=newsrno;
				printf("Enter new title name :\n");
				fflush(stdin);
				scanf("%s",&newtitle);
				strcpy(newtitle,v[i].title);
				printf("Enter new available number :\n");fflush(stdin);
				scanf("%d",&newavail);
				v[i].avail=newavail;
				printf("Enter new total no of cassetes :\n");fflush(stdin);
				scanf("%d",&newtotal);
				v[i].total=newtotal;
			}
			printf("New entries updated...:\n");
			break;
			//update();
		case 5:
			flag=1;
			break;
		//exit();
		}
	}
	while(flag!=1);
	}