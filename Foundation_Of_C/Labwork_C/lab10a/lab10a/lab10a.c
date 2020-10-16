#include<stdio.h>
void split(int *ptr,int piv,int s)
{
		int part1[10],part2[10],p1=0,p2=0,i,a,count1=0,count2=0,first=0,last=s-1;
		for(i=first;i<s;i++)
		{
			if(piv<=*(ptr+i))
			{
				part2[p2]=*(ptr+i);
				p2++;
				count2++;
			}
			else
			{
				part1[p1]=*(ptr+i);
				p1++;
				count1++;
			}
		}
		for(i=last;i>=0;i--)
		{
			if(piv<=*(ptr+last))
			{
				part2[p1]=*(ptr+i);
				p2++;
				count2++;
				last--;
			}
			else
			{
				part1[p1]=*(ptr+i);
				p1++;
				count1++;
				last--;
			}
		}
		printf("size of partition 1 :%d\n\n",count1);
		printf("size of partition 2 :%d\n\n",count2);
			for(i=0;i<p1-4;i--)
			{
				printf("%d\n",part1[i]);
			}

			for(i=0;i<p2-4;i++)
			{
				printf("%d\n",part2[i]);
			}
}
void main()
{
	int arr[20],size,i,pivot;
	printf("Enter array size \n");
	scanf("%d",&size);
	printf("Enter array elements \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter pivot element \n");
	scanf("%d",&pivot);
	split(arr,pivot,size);
}