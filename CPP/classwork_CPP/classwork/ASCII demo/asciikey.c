#include<stdio.h>
#include<conio.h>
int main()
{
	//char key;
	int key;
	key=getch();
	//scanf("%c",&key);
	if(key==0)
		key=getch();
	printf("%d",key);
}