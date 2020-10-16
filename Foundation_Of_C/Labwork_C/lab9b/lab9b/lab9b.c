#include<stdio.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main()
{
	int num1,num2,res1,res2,res3,*ptr,val=-20;
	printf("Enter first number \n");
	scanf("%d\n",&num1);
	printf("Enter second number \n");
	scanf("%d\n",&num2);
	if(num1>num2)
	{
		swap(&num1,&num2);
	}
	printf("Swappnig using Call by pointer reference  \n%d\n%d\n",num1,num2);
}