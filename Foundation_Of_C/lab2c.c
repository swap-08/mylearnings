#include<stdio.h>
#define add(a,b) (a+b)
#define sub(a,b) (a-b)
#define mul(a,b) (a*b)
#define div(a,b) (a/b)
#define mod(a,b) (a%b)
int main()
{
	int ch,a,b;
	printf("Enter two number\n");
	scanf("%d%d",&a,&b);
	printf("Enter choice \n1-Addition\n2-Subtraction\n3-Muitiplication\n4-Division\n5-Modulus\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("Addition %d\n",add(a,b));
		break;
		case 2:
		printf("Subtraction %d\n",sub(a,b));
		break;
		case 3:
		printf("Muitiplication %d\n",mul(a,b));
		break;
		case 4:
		printf("Division %d\n",div(a,b));
		break;
		case 5:
		printf("Modulus %d\n",mod(a,b));
		break;
		default:
		printf("Entered choice is incorrect\n");
	}
	return 0;
}