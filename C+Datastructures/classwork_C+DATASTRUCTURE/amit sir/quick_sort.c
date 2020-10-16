#include<stdio.h>
void sort(int a[],int left,int right)
{
	int pivot,l,r;
	l=left;
	r=right;
	pivot=a[left];
	while(left<right)
	{
		while((a[right]>=pivot)&&(left<right))
			right--;

		if(left!=right)
		{
			a[left]=a[right];
			left++;
		}

		while((a[left]<=pivot)&&(left<right))
			left++;

		if(left!=right)
		{
			a[right]=a[left];
			right--;
		}
	}

a[left]=pivot;
pivot=left;
left=l;
right=r;

	if(left<pivot)
		sort(a,left,pivot-1);

	if(right>pivot)
		sort(a,pivot+1,right);
}
main()
{
	int a[10];
	int i,left,right;
	
	//ACCEPT VALUES
	
	for(i=0;i<10;i++)
	{
		printf("enter the %d value:",i);
		scanf("%d",&a[i]);
	}

	left=0;
	right=9;

	sort(a,left,right);

	for(i=0;i<10;i++)
	  printf("%d\n",a[i]);
}
