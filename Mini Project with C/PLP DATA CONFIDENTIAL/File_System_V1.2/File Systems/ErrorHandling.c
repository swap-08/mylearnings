/****************************<File Header>**********************************/
/*!
@File: ErrorHandling.c
@brief Abstract: This file includes the Error handling part of the file system.
@Description: This file contains the functions which will handle the various errors
encountered during system operations.If the system encounters an error,that particular
error is captured and sent to the error log file.User can also see the contents of the 
error log file.
@Authors: Dhwani Patel,Sneha Nair
@Date: 04-01-2014
@Change History: <change history>
*/
/****************************************************************************/


#include <stdio.h>
#include "ErrorHandling.h"

/*
 * int copyToErrorFile(char *error_str)
 * Brief: function to log error in error log file
 * Params: char *error_str: string that contains file name, error description & timestamp
 * Return: Function returns TRUE after adding error to error log file else returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 04-01-2014
 * Change History: <change history>
 */
int copyToErrorFile(Error_Type f_tERR)
{
	FILE *l_pFile;

	//open error file in append mode
	l_pFile=fopen(ERROR_LOG_FILE, "a+");

	if(l_pFile == NULL)											//validation to check whether error file is opened
	{
		printf("\n\n Error Log File Cannot Be Loaded..!! \n");
		return FALSE;
	}
	else
	{
		//add error to error log file
		fwrite(&f_tERR, sizeof(f_tERR),1,l_pFile);
		fclose(l_pFile);
		printf("\n Encountered Error has been Copied to the Error File..!! \n");
		return TRUE;
	}
	
}
/*
 * int displayErrorFile()
 * Brief: function to display error log file
 * Params: No Parameters..
 * Return: Function returns TRUE displaying error log file else returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 04-01-2014
 * Change History: <change history>
 */
int displayErrorFile()
{
	FILE	   *l_pFile;
	Error_Type f_tERR;

	l_pFile=fopen(ERROR_LOG_FILE,"r");

	if(l_pFile == NULL)											//validation to check whether error file is opened
	{
		printf("\n\n Error Log File Cannot Be Loaded..!! \n");
		return FALSE;
	}
	else
	{
		printf("\n Error Log : \n");
		printf("\n----------------------------------------------------------------------\n\n");
		fread(&f_tERR,sizeof(f_tERR),1,l_pFile);
		while(!feof(l_pFile))
		{
			printf("\n File Name : %s \n",f_tERR.m_acFileName);
			printf("\n Error Details : %s \n",f_tERR.m_acDetail);
			printf("\n Occurance Time : %s \n",f_tERR.m_acOccuringTime);
			printf("\n----------------------------------------------------------------------\n\n");
			fread(&f_tERR,sizeof(f_tERR),1,l_pFile);
		}
		fclose(l_pFile);
		return TRUE;
	}
}