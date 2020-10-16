#include<stdio.h>
#include<math.h>
float compound_interest(float x,float y,float z)
	{
		return(x*pow((1+(y/100)),z));
	}
	int main()
	{
		float ci,p,r,yr;
		printf("Enter Principle amount\n");
		scanf("%f",&p);
		printf("Enter Rate of Interest\n");
		scanf("%f",&r);
		printf("Enter Number of Years\n");
		scanf("%f",&yr);
		ci=compound_interest(p,r,yr);
		printf("Compound Interest :%f\n",ci);
		return 0;
	}