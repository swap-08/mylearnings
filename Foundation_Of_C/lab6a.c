#include<stdio.h>
int main()
{
	int sum=0,i,j,c,num,num2,minimum,maximum,pos,minlocation,maxlocation;
	int a[6]={11,22,33,44,55,66};

	for(i=0;i<6;i++)
	{
		sum+=a[i];
	}

	printf("Sum  : %d\n\n",sum);
	printf("Enter number to be inserted\n");
	scanf("%d",&num);
	printf("Enter position to which the number is to be inserted\n");
	scanf("%d",&pos);
	a[pos-1]=num;
	printf("After insertion the array is\n\n");
	
	for(i=0;i<6;i++)
	{
		printf("%d\n",a[i]);
	}

	printf("Enter number which is to be deleted\n");
	scanf("%d",&num2);

	for(i=0;i<6;i++)
	{
		if(a[i]!=num2)
		{
			printf("Not present in Array\n");
		}
	}

	for(i=0;i<6;i++)
	{
		if(a[i]==num2)
		{
			a[i]=0;
		}
	}

	printf("After deletion the array is\n\n");
	for(i=0;i<6;i++)
	{
		printf("%d\n",a[i]);
	}

	//MINIMUM NUMBER

	    minimum = a[0];
	for ( c = 1 ; c < 6 ; c++ ) 
    {
        if ( a[c] < minimum ) 
        {
           minimum = a[c];
           minlocation = c+1;
        }
    } 
	printf("\nMinimum numnber in the array is\n%d",minimum);
	printf("\nMinimum numnber is at position\n%d\n",minlocation);

	//MAXIMUM NUMBER

	    maximum = a[0];
	for ( c = 1 ; c < 6 ; c++ ) 
    {
        if ( a[c] > maximum ) 
        {
           maximum = a[c];
           maxlocation = c+1;
        }
    } 
	printf("\nMinimum numnber in the array is\n%d",maximum);
	printf("\nMinimum numnber is at position\n%d\n",maxlocation);
	return 0;
}
