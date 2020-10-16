#include<stdio.h>
/*void sort(int *ptr,int lb,int ub);
//void binary_search(int *ptr,int lb,int ub,int pivot);
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

	//printf("Enter number to be search\n");
	//scanf("%d",&pivot);
	
	//function calling
	//binary_search(arr,lbound,ubound,pivot);

	//function calling

	display_array(arr,lbound,ubound);
}
void sort(int *ptr,int lb,int ub)
{
	int i,j,temp,flag=0;
	for(i=lb;i<ub-1-i;i++)
	{
		for(j=lb;j<ub-1-i;j++)
		{
			if(ptr[i]>ptr[i+1])
			{
				flag=1;
				printf("hello sort\n");
				temp=ptr[i];
				ptr[i]=ptr[i+1];
				ptr[i+1]=temp;
			}
		}
		if(flag==0)
			break;
	}

	printf("Array sorted successfully\n\n");
}
/*
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
}*/
void swap(int *ptr,int x,int y)
{
	int temp;
	temp=ptr[x];
	ptr[x]=ptr[y];
	ptr[y]=temp;
}

void quicksort(int *a,int first,int last)
{
	int pivot,temp,i,j;
	pivot=first;
	i=pivot+1;
	j=last;
	while(i<=j)
	{
		while(a[i]<a[pivot])
		{
			i++;
		}
		while(a[j]>a[pivot])
		{
			j--;
		}
		if(i<j)
		{
			//swap(a[i],a[j]);
			swap(a,i,j);
		//temp=a[i];
		//a[i]=a[j];
		//a[j]=temp;
		}
				//swap(a[pivot],a[j]);
				swap(a,pivot,j);
		//temp=a[pivot];
		//a[pivot]=a[j];
		//a[j]=temp;

		quicksort(a,first,j-1);
		quicksort(a,j+1,last);
	}
}
int main()
{
	int arr[8]={29,11,-3,-7,13,28,19,-33};
	int i;
	
	quicksort(arr,0,7);
	for(i=0;i<8;i++)
	{
		printf("%d\n",arr[i]);
	}
}