#include<stdio.h>
int totalpay(int x,int y)
{
	int temp1,temp2,temp3,temp4;
	if(y<=40)
		return(x*y);
	else if(y>40 && y<=60)
	{
		temp1=y-40;
		temp2=(x*40);
		temp3=(x*1.5*temp1);
		return(temp2+temp3);
	}
	else
	{
		temp1=x*40;
		temp2=y-60;
		temp3=(x*1.5*20);
		temp4=(x*2*temp2);
		return (temp1+temp3+temp4);
	}
}
int main()
{
	int hrs,rate,pay,total=0;
	do
	{
		printf("Enter Rate of pay\n");
		scanf("%d",&rate);
	if(rate==0)
	{
		break;
	}
		printf("Enter Number of hours\n");
		scanf("%d",&hrs);
		pay=totalpay(rate,hrs);
		printf("Pay at %d rupees/hr for %d hours is %d rupees\n\n",rate,hrs,pay);
		total=total+pay;
	}
	while(rate!=0);
		printf("Total pay is %d rupees\n",total);
}
	