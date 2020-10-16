#include<stdio.h>
int main()
{
	int dig,temp1,sum=0;
	printf("Enter two digit or three digit number\n");
	scanf("%d",&dig);
	if(dig>999)
	printf("Please enter two digit or three digit number\n");
	else
	{
	while(dig!=0)
	{
		temp1=dig%10;
		dig=dig/10;
		sum=sum+temp1;
	}
	printf("Sum of digit : %d\n",sum);
	}
	return 0;
}