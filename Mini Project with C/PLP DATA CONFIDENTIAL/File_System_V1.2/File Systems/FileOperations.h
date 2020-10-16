/****************************<File Header>**********************************/
/*!
@File: FileOperations.h
@brief Abstract: This header file contains all the file operation function prototypes.
@Author: Neeraj Narkar
@Date: 03-01-2014
@Change History: <change history>
*/
/****************************************************************************/

#include "SystemDefinitions.h"

/*
 * int checkFile(char f_acFileName[])
 * Brief: funtion to check whether the file already exists in the file system..
 * Params: char f_acFileName[] : character array that holds file name to be checked in the system..
 * Return: Function returns TRUE if file system exists else returns FALSE.. 
 */
int checkFile(char f_acFileName[]);

/*
 * int isMaxFiles()
 * Brief: funtion to check whether the maximum file capacity has reached..
 * Params: No Parameters..
 * Return: Function returns TRUE if maximum file limit is reached else returns FALSE..
 */

int isMaxFiles();

/*
 * int getEmptyDB()
 * Brief: funtion that returns empty data block number from the data block linklist..
 * Params: No Parameters..
 * Return: Function returns FALSE if there are no free blocks left else returns empty block number..
 */
int getEmptyDB();

/*
 * long int availableSpace()
 * Brief: funtion that returns available size in the system..
 * Params: No Parameters..
 * Return: Function returns available size in the system..
 */
long int availableSpace();

int isFileNameValid(char *l_pFileName);

/*
 * int createFile()
 * Brief: funtion to create a file in file system..
		  function also performs validations such as whether file name exists or system has reached maximum file capacity..
		  function creates a file & makes necessary updates in FAT table as well as data blocks..
 * Params: No Parameters..
 * Return: Function returns TRUE is file is created..For any other errors it returns FALSE..
 */
int createFile();

/*
 * int listAllFiles()
 * Brief: funtion to list all files in the file system..
 * Params: No Parameters..
 * Return: Function returns TRUE after displaying file list..if list is empty it returns FALSE..
 */
int listAllFiles();

/*
 * int displayFile()
 * Brief: funtion to display a perticular file attributes & data stored in it..
 * Params: No Parameters..
 * Return: Function returns TRUE after displaying file attributes & contents else returns FALSE..
 */
int displayFile();

/*
 * int deleteFile()
 * Brief: funtion to delete a file from the file system..
 * Params: No Parameters..
 * Return: Function returns TRUE after deleting the file else returns FALSE..
 */
int deleteFile();

/*
 * int changeName()
 * Brief: funtion to rename a file..
 * Params: No Parameters..
 * Return: Function returns TRUE after renaming a file else returns FALSE..
 */
int changeName();

/*
 * int appendToFile(char *f_cFileName)
 * Brief: funtion to append data to the file
 * Params: char *f_cFileName : contains file name to which user wants to append the contents
 * Return: Function returns TRUE appending data to the file else returns FALSE..
 */
int appendToFile(char *f_cFileName);

/*
 * int overwriteFile(char *f_cFileName)
 * Brief: funtion to append data to the file
 * Params: char *f_cFileName : contains file name that user wants to overwrite
 * Return: Function returns TRUE overwrite data to the file else returns FALSE..
 */
int overwriteFile(char *f_cFileName);

/*
 * int changeContent()
 * Brief: funtion to change file contents..
 * Params: No parameters..
 * Return: Function returns TRUE after successful execution else returns FALSE..
 */
int changeContent();

/*
 * int changeFileMode()
 * Brief: funtion to change file access permissions..
 * Params: No Parameters..
 * Return: Function returns TRUE after changing the file permissions else returns FALSE..
 */
int changeFileMode();

/*
 * int modifyFile()
 * Brief: funtion modify file..
			function inturn calls two functions depending upon user input to change
				1)file contents
				2)file permissions
 * Params: No Parameters..
 * Return: Function returns TRUE after successful execution..
 */
int modifyFile();