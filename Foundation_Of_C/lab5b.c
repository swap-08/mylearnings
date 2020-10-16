#include<stdio.h>
int absolute(int x)
{
	if(x>=0)
		return(x);
	else
		return(-1*x);
}
int main()
{
	int num,abs;
	printf("Enter any number\n");
	scanf("%d",&num);
	abs=absolute(num);
	printf("Aboslute value is :%d\n",abs);
	return 0;
}