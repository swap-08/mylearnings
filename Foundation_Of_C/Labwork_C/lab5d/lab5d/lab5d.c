#include<stdio.h>
int fact(int x)
{
	if(x==0)
		return 1;
	else
	{
		return(x*fact(x-1));
	}
}
int main()
{
	int n,r,temp1,temp2;
	printf("Enter value of n\n");
	scanf("%d",&n);
	printf("Enter value of r\n");
	scanf("%d",&r);
	temp1=fact(n)/(fact(r)*fact(n-r));
	printf("nCr   :   %d\n",temp1);
	temp2=fact(n)/fact(n-r);
	printf("nPr   :   %d\n",temp2);

}


