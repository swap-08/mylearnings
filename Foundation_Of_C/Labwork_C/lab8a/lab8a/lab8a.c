#include<stdio.h>
int main()
{
	int *ptr1;
	int *ptr2;
	int a=10,b=20,diff,val=2;
	printf(" Number 1 :\t%d\n\n",a);
	printf(" Number 2 :\t%d\n\n",b);
	ptr1=&a;
	ptr2=&b;
	printf(" After pointer\n\n");
	printf(" Number 1 :\t%d\n\n",*ptr1);
	printf(" Number 2 :\t%d\n\n",*ptr2);
	diff=*ptr1-*ptr2;
	printf(" Difference :\t%d\n\n",diff);
	printf(" After addition constant value 2  with ptr 1:\t%d\n\n",*ptr1+val);
	printf(" After addition constant value 2 with ptr2 :\t%d\n\n",*ptr2+val);
	printf(" After Subtracting constant value 2 with ptr1 :\t%d\n\n",*ptr1-val);
	printf(" After Subtracting constant value 2 with ptr2 :\t%d\n\n",*ptr2-val);
}