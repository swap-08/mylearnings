#ifndef HEADACCEPT.H
#define HEAD_H
int *accept(int size)//,int number)
{
	int element_number,*a,temp;

	a=(int *)malloc(sizeof(a)*size);			//array size

	printf("Enter elements\n");
	for(element_number=0;element_number<size;element_number++)
	{
		scanf("%d",&a[element_number]);
		//printf("ele  %d",a[element_number]);
	}
	return a;
}

void display(int *a,int size)
{
	
	int element_number;
	printf("Entered elements are :\n");
	printf("size :%d\n",size);
	for(element_number=0;element_number<size;element_number++)
	{
		printf("%d\n",a[element_number]);
	}
}
void sort_array(int *a,int size)
{
	int i,j,temp;
	for(i=0;i<size;i++)
	{
		j=i-1;
		temp=a[i];
		while(temp<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	printf("Array sorted successfully...\n\n");
}
void reverse_array(int *a,int size)
{
	int i,j;
	i=0;
	j=size-1;
	while(i<=j)
	{
		int temp;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		i++;
		j--;
	}
	printf("Array reverse successfully...\n\n");
}

void count_odd(int *a,int size)
{
	int i,count=0;
	for(i=0;i<size;i++)
	{
		if(a[i]%2!=0)
			count++;
	}
	printf("Number of odd elements :%d\n\n",count);
}

void count_even(int *a,int size)
{
	int i,count=0;
	for(i=0;i<size;i++)
	{
		if(0==a[i]%2)
			count++;
	}
	printf("Number of even elements :%d\n\n",count);
}

void count_prime(int *a,int size)
{
	int i,j,count=0,flag;
	for (i=0;i<size;i++) 
	{
		flag=0;
		for (j=1;j<=a[i];j++)
		{
			if (a[i]%j==0)
			{
				flag++;
			}
		} 
		if(flag==2)
		{
			count++;
		}
	}
	printf("Number of prime elements :%d\n\n",count);
}
void count_maximum(int *a,int size)
{
	int maximum,i;
	maximum=a[0];
	for(i=1;i<size;i++) 
    {
        if(a[i]>maximum ) 
        {
           maximum=a[i];
        }
    }
	printf("Maxiimum number :\t%d\n\n",maximum);
}

void count_minimum(int *a,int size)
{
	int minimum,i;
	minimum=a[0];
	for(i=1;i<size;i++) 
    {
        if(a[i]<minimum ) 
        {
           minimum=a[i];
        }
    }
	printf("Minimum number :\t%d\n\n",minimum);
}
void search_value(int *a,int size)
{
	int element,i,flag=0,index;
	printf("Enter element to be search\n");
	scanf("%d",&element);
	for(i=0;i<size;i++)
	{
		if(a[i]==element)
		{
			flag=1;
			index=i;
		}
	}
	if(1==flag)
		printf("Element find at position:\t %d\n",index+1);
	else
		printf("Element not found...\n");
}

#endif;