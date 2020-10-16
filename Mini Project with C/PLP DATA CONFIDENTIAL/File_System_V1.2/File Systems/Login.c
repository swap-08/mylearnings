#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Login.h"
/*
 * int checkLength(char *l_pTemp)
 * Brief: funtion for checking length of character array..
 * Params: Function takes character pointer which contains array of character..
 * Return: Function returns TRUE lenght is less then 15 else returns FALSE..
 * Authors: Swapnil
 * Date: 09-01-2014
 * Change History: <change history>
 */
int checkLength(char *l_pTemp)
{
	if(strlen(l_pTemp)> USER_LENGTH)
	{
		printf("\n\n Length of Password Exceed 15..!! \n");
		printf("\n Press any key to continue..!!");
		getch();
		return FALSE;
	}
	else
		return TRUE;
}
/*
 * void add_User()
 * Brief: funtion to add user to the file system..
		  function takes user name and password from admin and writes it into the file..
 * Params: No Parameters..
 * Return: void..
 * Authors: Swapnil
 * Date: 09-01-2014
 * Change History: <change history>
 */
void add_User()
{
	FILE		*l_pfp;
	char		l_acTempUser[USER_LENGTH],l_acTempPasswrd[USER_LENGTH];		
	char		l_acTemp[USER_LENGTH];
	char		l_cCharacter;
	int			l_nIndex,l_nNumber_of_user,l_nCounter=0;
	USER_LOGIN	l_tUser;
			
	l_pfp=fopen(USER_FILE,"a+");
	
	if(l_pfp==NULL)
	{
		printf("\n\n File Cannot Be Opened..!! \n");
		fclose(l_pfp);
		return FALSE;
	}

	printf("\n Enter User Name to Add : ");
	scanf("%s",l_acTempUser);
	strcpy(l_tUser.l_acUserName,l_acTempUser);
	printf("\n Enter Password : ");
	l_cCharacter=getch();

	while(l_cCharacter != CARRIAGE_RETURN)					//ASCII value for enter 
	{
		printf("*");
		l_acTemp[l_nCounter++]=l_cCharacter;
		l_cCharacter=getch();
	}
	l_acTemp[l_nCounter]='\0';

	strcpy(l_tUser.l_acPassword,l_acTemp);
	
	fseek(l_pfp,0,SEEK_END);

	fwrite(&l_tUser,sizeof(l_tUser),1,l_pfp);

	fclose(l_pfp);

	printf("\n\n User Added Succesfully to the System..!! \n");
}
/*
 * int admin_Login()
 * Brief: funtion for authentication of admin..
 * Params: No Parameters..
 * Return: Function returns TRUE if successfull authentication else returns FALSE..
 * Authors: Swapnil
 * Date: 09-01-2014
 * Change History: <change history>
 */
int admin_Login()
{
	FILE *l_pfp;
	char l_acPassword[]=ADMIN_PASSWORD,l_acTemp[TEMP_LENGTH];
	char l_cCharacter;
	int l_nIndex=0;
	USER_LOGIN l_tUser;

	l_pfp=fopen(USER_FILE,"a+");
	if(l_pfp==NULL)
	{
		printf("\n\n File Cannot Be Opened..!! \n");
		fclose(l_pfp);
		return FALSE;
	}

	strcpy(l_tUser.l_acUserName,ADMIN_USERNAME);
	strcpy(l_tUser.l_acPassword,ADMIN_PASSWORD);
	fwrite(&l_tUser,sizeof(l_tUser),1,l_pfp);
	fclose(l_pfp);

    printf("\n Enter the password : ");
	l_cCharacter=getch();
	
    while(l_cCharacter != CARRIAGE_RETURN)		//ascii value for enter 
    {
		printf("*");
	    l_acTemp[l_nIndex++]=l_cCharacter;
		l_cCharacter=getch();
	}
	l_acTemp[l_nIndex]='\0';

	if(checkLength(l_acTemp)== TRUE)			//length of character array is less then 15
	{
		if(strcmp(l_acTemp,l_acPassword) == 0)
		{
			printf("\n\n Login Successful..!! \n\n Welcome Admin..!! \n");
			printf("\n Press any key to continue..!!");
			getch();
			return TRUE;
		}
		else
		{
			printf("\n\n Incorrect Password..!! \n\n Login Unsuccessful..!! \n");
			printf("\n Press any key to continue..!!");
			getch();
			return FALSE;
		}
	}
	else
	{
		printf("\n\n Length Of Password Exceed 15 Characters!! \n");
		printf("\n Press any key to continue..!!");
		getch();
		return FALSE;
	}
}
/*
 * int user_Login()
 * Brief: funtion for authentication of users..
 * Params: No Parameters..
 * Return: Function returns TRUE if successfull authentication else returns FALSE..
 * Authors: Swapnil
 * Date: 09-01-2014
 * Change History: <change history>
 */

int user_Login()
{
	FILE *l_pfp;
	char l_acTempPassword[TEMP_LENGTH],l_acTempUserName[TEMP_LENGTH];
	char l_cCharacter;
	int l_nIndex=0,l_nFlag=0,l_nCounter=0;
	USER_LOGIN l_tUser;

	printf("\n Enter User Name : ");
	scanf("%s",l_acTempUserName);
    printf("\n Enter the password : ");
	l_cCharacter=getch();

	while(l_cCharacter != CARRIAGE_RETURN)					//ASCII value for enter
	{
		printf("*");
		l_acTempPassword[l_nCounter++]=l_cCharacter;
		l_cCharacter=getch();
	}
	l_acTempPassword[l_nCounter]='\0';


	if(checkLength(l_acTempUserName)== TRUE && checkLength(l_acTempPassword) == TRUE)			//length of character array is less then 15
	{
		l_pfp=fopen(USER_FILE,"r");
		
		if(l_pfp==NULL)
		{
			printf("\n\n File Cannot Be Opened..!! \n");
			fclose(l_pfp);
			return FALSE;
		}

		fread(&l_tUser,sizeof(l_tUser),1,l_pfp);

		while(!feof(l_pfp))
		{
			if( strcmp(l_acTempUserName,l_tUser.l_acUserName) == 0 &&
				strcmp(l_acTempPassword,l_tUser.l_acPassword) == 0 )
			{
				l_nFlag=1;
			}

			fread(&l_tUser,sizeof(l_tUser),1,l_pfp);
		}
		if( 1==l_nFlag )
		{
			printf("\n\n Login Successful..!! \n\n Welcome User..!! \n");
			printf("\n Press any key to continue..!!");
			getch();
			return TRUE;
		}
		else
		{
			printf("\n\n Incorrect Password..!! \n\n Login Unsuccessful..!! \n");
			printf("\n Press any key to continue..!!");
			getch();
			return FALSE;
		}
	}
	else
	{
		printf("\n\n Length Of UserName or Password Exceeds 15 Character..!! \n");
		printf("\n Press any key to continue..!!");
		getch();
		return FALSE;
	}
	fclose(l_pfp);
	getch();
}