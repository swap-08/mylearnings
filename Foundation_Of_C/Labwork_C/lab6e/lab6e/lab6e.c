#include<stdio.h>
int main()
{
	int size1,size2,i,j,k=0,nsize;
	int a[20];
	int b[20];
	int merge[40];
	printf("Enter size of array1\n");
	scanf("%d",&size1);
	printf("Enter size of array2\n");
	scanf("%d",&size2);
	nsize=size1+size2;
	printf("Enter elements of array1 in ascending ordeer\t\n");
	for(i=0;i<size1;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter elements of array2 in ascending order\t\n");
	for(i=0;i<size2;i++)
	{
		scanf("%d",&b[i]);	
	}
	for(i=0;i<size1;i++)
	{
		merge[i]=a[i];
	}
	for(i=0;i<(nsize-size1);i++)
	{
		merge[i+size1]=b[i];
	}
	printf("After merging two arrays : \n");
	for(i=0;i<nsize;i++)
	{
		printf("%d\n",merge[i]);
	}
}





