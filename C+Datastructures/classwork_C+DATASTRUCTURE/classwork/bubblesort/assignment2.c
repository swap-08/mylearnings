#include<stdio.h>
void sort(int *ptr,int lb,int ub);
void binary_search(int *ptr,int lb,int ub,int pivot);
void display_array(int *ptr,int lb,int ub);
int main()
{
	int arr[30],num,i,pivot,lbound,ubound;
	printf("Enter number of element to be entered\n");
	scanf("%d",&num);
	printf("Enter array elements\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter Lower bound\n");
	scanf("%d",&lbound);
	printf("Enter Upper bound\n");
	scanf("%d",&ubound);
	
	//function calling

	sort(arr,lbound,ubound,num);

	printf("Enter number to be search\n");
	scanf("%d",&pivot);
	
	//function calling
	binary_search(arr,lbound,ubound,pivot);

	//function calling

	display_array(arr,lbound,ubound);
}
void sort(int *ptr,int lb,int ub)
{
	int i,j,temp;
	for(i=lb;i<ub-1;i++)
	{
		for(j=lb;j<ub-1;j++)
		{
			if(ptr[i]>ptr[i+1])
			{
				temp=ptr[i];
				ptr[i]=ptr[i+1];
				ptr[i+1]=temp;
			}
		}
	}

	printf("Array sorted successfully\n\n");
}
void binary_search(int *ptr,int lb,int ub,int pivot)
{
	int mid,temp;
	temp=lb+ub;
	mid=temp/2;
	while(ptr[mid]!=pivot && lb<=ub)
	{
		if(ptr[mid]<pivot)
			lb=mid+1;
		else
			ub=mid-1;
		mid=(lb+ub)/2;
	}
	if(pivot==ptr[mid])
		printf("\aElement found at position:\t%d\n",mid);
	else
		printf("\aElement not found\n");

}
void display_array(int *ptr,int lb,int ub)
{
	int i;
	printf("sorted array\n");
	for(i=lb;i<ub;i++)
	{
		printf("%d\n",ptr[i]);
	}
}