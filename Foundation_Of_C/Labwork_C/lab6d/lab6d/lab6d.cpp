#include<stdio.h>
int main()
{
	int i,j,k,count=0;
	int a[3][4]={1,0,0,4,0,0,0,2,0,6,0,0};
	k=0;
	int temp[3],temp1[4],temp2[4],temp3[4];
	printf("Original matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n\nConverted Matrix\n\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]!=0)
			{
					temp1[k]=i;
					temp2[k]=j;
					temp3[k]=a[i][j];
					k++;			
			}
		}
	}
	temp[0]=3;
	temp[1]=4;
	temp[2]=k;
	for(i=0;i<3;i++)
	{
	printf("%d\t",temp[i]);
	}
	printf("\n");
		for(i=0;i<4;i++)
		{
			printf("%d\t",temp1[i]);
			printf("%d\t",temp2[i]);
			printf("%d\t",temp3[i]);
			printf("\n");	
		}
}