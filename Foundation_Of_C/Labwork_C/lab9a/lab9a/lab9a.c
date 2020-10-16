#include<stdio.h>
int absolute1(int x)
{
	if(x<0)
		return x*(-1);
	else
		return x;
}
int absolute2(int *x)
{
	if(*x<0)
		return *(x)*(-1);
	else
		return *x;
}
int main()
{
	int num,res1,res2,res3,*ptr,val=-20;
	printf("Enter any integer\n");
	scanf("%d\n",&num);
	res1=absolute1(num);
	printf("Absolute value using call by value :\t%d\n",res1);
	res2=absolute2(&num);
	printf("Absolute value using call by reference :\t%d\n",res2);
	res3=absolute1(val);
	printf("Absolute value using appropriate value :\t%d\n",res3);
}