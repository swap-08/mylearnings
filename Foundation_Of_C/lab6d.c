#include<stdio.h>
int main()
{
	int i,j,k,count=0;
	int a[3][4]={1,0,0,4,0,0,0,2,0,6,0,0};
	int b[4][3];
	int temp1[3],temp2[3],temp3[3];
	
	printf("Original matrix\n");
		//printing original matrix
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

		//calculating non zero element index and the element

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

		for(i=0;i<4;i++)
	{
		printf("%d\t",temp1[i]);
		printf("%d\t",temp2[i]);
		printf("%d\t",temp3[i]);
		printf("\n");	
	}
	return 0;
}