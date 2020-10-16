#include<stdio.h>
int main()
{
	int a,l,r;
	printf("Enter any number\n");
	scanf("%d",&a);
	l=a>>3;
	printf("\nAfter left shift :%d",l);
	r=a<<2;
	printf("\nAfter right shift :%d\n",r);
	return 0;
}