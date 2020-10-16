#include<stdio.h>
int main()
{
	int arr[4]={8,7,3,5};
	int i,j,temp;
	
	
	
	//,temp=arr[last],index,temp2;
/*	for(i=0;i<5;i++)
	{
		(arr[i]>arr[last-1])
		{
			index=i;
			break;
		}
	}
	printf("index %d\n",index);
	temp2=arr[index];
	printf("temp2%d\n",temp2);
	arr[index]=arr[last-1];
	arr[index+1]=temp;

	for(i=index;i<5;i++)
	{
		arr[index++]=arr[index];
	}
*/
	
	for(i=0;i<4;i++)
	{
		j=i-1;
		temp=arr[i];
		//printf("temp%d\n",temp);
		
		while(temp<arr[j] && j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
		for(i=0;i<4;i++)
	{
		printf("%d\n",arr[i]);
	}
}