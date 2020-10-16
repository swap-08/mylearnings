#include<stdio.h>
int main()
{
	int *ptr;
	int x=2,y=3;
		printf("y  :%d\n",y);
	ptr=&x;
	ptr=&y;
	*ptr=10;
	printf("x  :%d\n",x);
	printf("y  :%d\n",y);
	printf("*ptr  :%d\n",*ptr);
	printf("ptr  :%d\n",ptr);
}