#include<stdio.h>
void calculate(float,float,float);	//FUNCTION PROTOTYPE
void main()
{

	float mpt_marks,mtt_marks,assign_marks,total;	//data definition

	/* taking values from coordinator*/

	printf("Enter Module Practical Test Marks of student\n");
	scanf("%f",&mpt_marks);
	printf("Enter Module Theory Test Marks of student\n");
	scanf("%f",&mtt_marks);
	printf("Enter Assignment Marks of student\n");
	scanf("%f",&assign_marks);
	
	/*callinG function*/

	calculate(mpt_marks,mtt_marks,assign_marks);
}

		/*FUNCTION DEFINITION*/
void calculate(float p,float t,float a)
{
	float total,percent,temp1,temp2,temp3;
	int score;
	temp1=p*0.7;
	temp2=t*0.15;
	temp3=a*0.15;
	total=temp1+temp2+temp3;
	percent=total;
	/*PRINTING MARKKS*/
		printf("***********************************************\n");
		printf("MARKS OF THE STUDENT\n");
		printf("***********************************************\n");
		printf("MODULE PRACTICAL TEST:\n%f\n\n",p);
		printf("MARKS OF THE STUDENT IN MODULE THEORY TEST:\n%f\n\n",t);
		printf("MARKS OF THE STUDENT IN ASSIGNMENT:\n%f\n\n",a);
		printf("TOTAL MARKS OF THE STUDENT:\n%f\n\n",total);
		printf("PERCENTAGE:\n%f\n\n",percent);

		if(percent>0 && percent<50)
		{
			printf("SCORE \t:0\t");
			printf("STATUS \t:FAIL\n\n");
			printf("TERMINATION FROM ORGANIZATION\n\n");
			printf("THANK YOU..\n");
		}
		if(percent>=50 && percent<60)
		{
			printf("SCORE \t:1\t");
			printf("STATUS \t:FAIL\n\n");
			printf("TERMINATION FROM ORGANIZATION\n\n");
			printf("THANK YOU..\n");
		}
		if(percent>=60 && percent<70)
		{
			printf("SCORE \t:2\t");
			printf("STATUS \t:PASS\n\n");
			printf("STUDENT IS ELIGIBLE\n\n");
			printf("CONGRATULATION..\n\nTHANK YOU..\n");
		}
		if(percent>=70 && percent<80)
		{
			printf("SCORE \t:3\t");
			printf("STATUS \t:PASS\n");
			printf("STUDENT IS ELIGIBLE\n\n");
			printf("CONGRATULATION..\n\nTHANK YOU..\n");
		}
		if(percent>=80 && percent<90)
		{
			printf("SCORE \t:4\t");
			printf("STATUS \t:PASS\n");
			printf("STUDENT IS ELIGIBLE\n\n");
			printf("CONGRATULATION..\n\nTHANK YOU..\n");
		}
		if(percent>=90 && percent<=100)
		{
			printf("SCORE \t:5\t");
			printf("STATUS \t:PASS\n");
			printf("STUDENT IS ELIGIBLE\n\n");
			printf("CONGRATULATION..\nTHANK YOU..\n");
		}
}		//END OF FUNCTION
