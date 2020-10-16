#include<stdio.h>
int main()
{
	int a;
	printf("Enter any number\n");
	scanf("%d",&a);
			switch(a)
		{
		case 1:
				printf("Monday\n");
				break;
		case 2:
				printf("Tueday\n");
				break;
		case 3:
				printf("Wednesday\n");
				break;
		case 4:
				printf("Thursday\n");
				break;
		case 5:
				printf("Friday\n");
				break;
		case 6:
				printf("Staurday\n");
				break;
		case 7:
				printf("Sunday\n");
				break;
		default:
			printf("Entered number is incorrect\n");
		}
	return 0;
}

	
