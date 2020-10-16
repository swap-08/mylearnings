#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,k;
	int a[10],b[10],res[10];
	for(i=0;i<10;i++)
	{
		printf("Enter %d  element for array 1\t\t",i+1);
		scanf("%d",&a[i]);
	}
		for(i=0;i<10;i++)
	{
		printf("Enter %d element for array2\t\t",i+1);
		scanf("%d",&b[i]);
	}
		for(i=0;i<10;i++)
	{
		res[i]=pow(a[i],2)+pow(b[i],2);
	}
		for(i=0;i<10;i++)
	{
		printf("\n\nResult of %d element of array1 and array2 is :  %d \n",i+1,res[i]);
	}

}