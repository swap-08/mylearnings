/****************************<File Header>**********************************/
/*!
@File: Errorhandling.h
@brief Abstract: This header file contains all the error handling function prototypes.
@Author: Dhwani Patel,Sneha Nair
@Date: 04-01-2014
@Change History: <change history>
*/
/****************************************************************************/

#include "SystemDefinitions.h"

/*
 * int copyToErrorFile(char *error_str)
 * Brief: function to log all the errors encountered during the file system operations into an
   error log file.
 * Params: char *error_str: string that contains file name, error description & timestamp
 * Return: Function returns TRUE after adding error to error log file else returns FALSE..

 */
int copyToErrorFile(Error_Type f_tERR);


/*
 * int displayErrorFile()
 * Brief: function to display error log file and its contents.This file contains all the errors
  which the system encountered during the file system operations.
 * Params: No Parameters..
 * Return: Function returns TRUE displaying error log file else returns FALSE..
 */
int displayErrorFile();