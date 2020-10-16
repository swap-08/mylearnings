#include<stdio.h>
int main()
{
	int num,n;
	printf("Enter any number\n");
	scanf("%d",&num);
	while(num!=0)
	{
		n=num%10;
		if(n==0)
		{
			num=num/10;
			continue;
		}
		else
		{
			printf("%d",n);
			num=num/10;
		}
	}
			printf("\n");
	return 0;
}