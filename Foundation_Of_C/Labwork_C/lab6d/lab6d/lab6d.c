#include<stdio.h>
int main()
{
	int i,j,k,count=0;
	int a[3][4]={1,0,0,4,0,0,0,2,0,6,0,0};
	int b[4][3];
	int temp1[3],temp2[3],temp3[3];
	printf("Original matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
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
	/*/b[0][0]=3;
	//b[0][1]=4;
	//b[0][3]=count;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]!=0)
			{
				for(k=0;k<4;k++)
				{
					
					//k++;
				}
			}

		}
	}*/
	//for(i=0;i<3;i++)
	//{
		for(i=0;i<4;i++)
		{
			printf("%d\t",temp1[i]);
			printf("%d\t",temp2[i]);
			printf("%d\t",temp3[i]);
			printf("\n");	
		}

		/*for(i=0;i<4;i++)
		{
		//	printf("%d\t",temp1[i]);
			printf("\n%d\t",temp2[i]);
		//	printf("\n%d\t",temp3[i]);
		}
		printf("\n");
		for(i=0;i<4;i++)
		{
		//	printf("\n%d\t",temp1[i]);
		//	printf("\n%d\t",temp2[i]);
			printf("%d\t",temp3[i]);
		}
		printf("\n");
*/

}