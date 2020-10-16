#include<stdio.h>
int main()
{
	int a,b,c,g;
	printf("Enter 1st number \n");
	scanf("%d",&a);
	printf("Enter 2nd number \n");
	scanf("%d",&b);
	printf("Enter 3rd number \n");
	scanf("%d",&c);
	g=a<b?(a<c?a:c):(b<c?b:c);
	printf("Minimum number is %d\n",g);
}