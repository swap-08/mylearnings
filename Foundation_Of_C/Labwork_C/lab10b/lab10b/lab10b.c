#include<stdio.h>
int replace_char(char *str,char old_char,char new_char)
{
	int len,i,count=0;
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(*(str+i)==new_char)
		{
			*(str+i)=new_char;
			count++;
		}
	}
	return(count);

}
int main()
{
	char string[25],ch_old,ch_new;
	int countc;
	printf("Enter any string\n");
	
	scanf("%s\n",string);
	fflush(stdin);

	printf("Enter old character which is to be replaced\n");
	
	scanf("%c\n",&ch_old);
	fflush(stdin);
	
	printf("Enter new character which is to be placed\n");
	
	scanf("%c\n",&ch_new);
	fflush(stdin);
	
	countc=replace_char(&string,ch_old,ch_new);
	printf("Number of times the character is replaced  : %d\n",countc);
	printf("After replacing with new character  : %s\n",string);
}