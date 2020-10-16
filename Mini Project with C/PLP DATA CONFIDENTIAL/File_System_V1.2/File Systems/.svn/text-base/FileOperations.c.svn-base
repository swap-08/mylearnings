/****************************<File Header>**********************************/
/*!
@File: FileOperations.c
@brief Abstract: This file contains the functions to perform various operations on the file system.
@Description: FileOperations.c has all the functions required to perform various operations on the file system.
This file includes functions to create file,check existence of the file,list all files,display specific file,
delete file,check the number of files present in the system,check file system size,change file mode,edit file and rename file.
Various validations have been done to check whether the user is entering correct input or not.The errors 
encountered are sent to the error log file.
@Author: Dhwani Patel,Neeraj Narkar,Sneha Nair
@Date: 03-01-2014
@Change History: <change history>
*/
/****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "FileOperations.h"

/*
 * int checkFile(char f_acFileName[])
 * Brief: function to check whether the file already exists in the file system..
 * Params: char f_acFileName[] : character array that holds file name to be checked in the system..
 * Return: Function returns TRUE if file system exists else returns FALSE.. 
 * Authors: Neeraj Narkar
 * Date: 03-01-2014
 * Change History: <change history>
 */
int checkFile(char f_acFileName[])
{
	FNODE		*l_pFatNode;
	l_pFatNode = g_pFatStart;

	while(l_pFatNode != NULL)
	{
		if(strcmp(l_pFatNode->m_tFat.m_acFileName,f_acFileName) == 0)		//checks whether file with name already exists
		{
			printf("\n File Already Exist..!! \n");
			return TRUE;
		}
		else
		{
			l_pFatNode = l_pFatNode->m_pNext;
		}
	}
	return FALSE;
}

/*
 * int isMaxFiles()
 * Brief: funtion to check whether the maximum file capacity has reached..
 * Params: No Parameters..
 * Return: Function returns TRUE if maximum file limit is reached else returns FALSE..
 * Authors: Neeraj Narkar
 * Date: 07-01-2014
 * Change History: <change history>
 */

int isMaxFiles()
{
	int			l_nCount=0;
	FNODE		*l_pFatNode;
	Error_Type  l_tERR;
	time        (&time1);

	l_pFatNode = g_pFatStart;

	while(l_pFatNode != NULL)
	{
		l_nCount++;
		l_pFatNode = l_pFatNode->m_pNext;
	}

	if (l_nCount == MAX_FILES)											//checks whether maximum file limit is reached..
	{
		printf("\n Maximum File Limit (%d) is Reached..!! \n Cannot Create More Files..!! \n",l_nCount);
		strcpy(l_tERR.m_acFileName," N.A. ");
		strcpy(l_tERR.m_acDetail,"Maximum File Limit is Reached..!! Cannot Create More Files..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*
 * int getEmptyDB()
 * Brief: funtion that returns empty data block number from the data block linkedlist..
 * Params: No Parameters..
 * Return: Function returns FALSE if there are no free blocks left else returns empty block number..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 03-01-2014
 * Change History: <change history>
 */
int getEmptyDB()
{
	int			l_nDbNumber;
	DBNODE		*l_pDbTemp;
	Error_Type  l_tERR;
	time        (&time1);

	for (l_pDbTemp=g_pDbStart;l_pDbTemp!=NULL;l_pDbTemp=l_pDbTemp->m_pNext)
	{
		if(l_pDbTemp->m_tDBlock.m_nIsEmpty == 1)							//checks whether datablock is empty in the linkedlist
		{
			l_nDbNumber = l_pDbTemp->m_tDBlock.m_nIndex;					//if yes then copy data block index number into a variable to return
			break;
		}
	}

	if(l_pDbTemp == NULL)													//if no,that means data blocks are empty then return FALSE
	{
		printf("\n Free Data Block is Not Available..!! \n");
		strcpy(l_tERR.m_acFileName," N.A. ");
		strcpy(l_tERR.m_acDetail,"Free Data Block is Not Available..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}

	return l_nDbNumber;
}

/*
 * int availableSpace()
 * Brief: funtion that returns available number of free data blocks in the system..
 * Params: No Parameters..
 * Return: Function returns available number of free data blocks in the system..
 * Authors:Neeraj Narkar
 * Date: 06-01-2014
 * Change History: <change history>
 */
int availableSpace()
{
	DBNODE		*l_pDbTemp;
	int			l_nCount=0;

	for (l_pDbTemp=g_pDbStart;l_pDbTemp!=NULL;l_pDbTemp=l_pDbTemp->m_pNext)
	{
		//checks whether datablock is empty in the linkedlist
		if(l_pDbTemp->m_tDBlock.m_nIsEmpty == 1)							
		{
			l_nCount++;														//counts number of blocks
		}
	}

	return l_nCount;
}
/*
 * int isFileNameValid(char *l_pFileName)
 * Brief: funtion Validates the file name and returns true if correct else returns false..
 * Params: Function takes Character array of file name..
 * Return: Function returns True is file name validates else returns false..
 * Authors: Swapnil,Neeraj Narkar
 * Date: 09-01-2014
 * Change History: <change history>
 */
int isFileNameValid(char *l_pFileName)
{
	int l_nCount,l_nIndex;

	l_nCount = strlen(l_pFileName);
	
	if(l_nCount == 0)										//check whether user has entered file name										
	{
		printf("\n The File Name Not Entered..!! \n");
		return FALSE;
	}
	else if(l_nCount > FNAME_SIZE)								//check whether name exceeds 255 characters
	{
		printf("\n The File Name Exceeds the Limit..!! \n");
		return FALSE;
	}
	else if(checkFile(l_pFileName) == TRUE)						//check whether file with this name already exists
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

/*
 * int createFile()
 * Brief: funtion to create a file in file system..
		  function also performs validations such as whether file name exists or system has reached maximum file capacity..
		  function creates a file & makes necessary updates in FAT table as well as data blocks..
 * Params: No Parameters..
 * Return: Function returns TRUE is file is created..For any other errors it returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 03-01-2014
 * Change History: <change history>
 */
int createFile()
{
	FAT_Type	l_tFat;
	DBNODE		*l_pDbTemp;
	FILE		*l_pFile;
	Error_Type  l_tERR;
	

	char		l_cChar,l_cChoice;
	char		l_acTempName[TEMP_LENGTH];
	int			l_nCount = 0;
	int			l_nFlag,l_nIndex;

	time        (&time1);

	//check whether maximum file capacity is reached
	if ( isMaxFiles() == TRUE )										
	{
		return FALSE;
	}
	do
	{
		printf("\n Enter the File Name : ");				      //take file name from the user
		fflush(stdin);
		gets(l_acTempName);

		l_nFlag=0;
		l_cChoice='N';

		//check whether user entered file name is valid
		l_nFlag = isFileNameValid(l_acTempName);

		if(l_nFlag == FALSE)											
		{
			printf("\n Do you want to try again?? (Y/N) : ");
			fflush(stdin);
			scanf("%c",&l_cChoice);
		}
	}while(l_cChoice != 'N' && l_cChoice != 'n');           //continue until user enters 'n' or 'N' for no

	if (l_nFlag==FALSE)
	{
		return FALSE;
	}
	
	strcpy(l_tFat.m_acFileName,l_acTempName);
	l_tFat.m_nFileSize = 0;
	l_tFat.m_nStartBlockNo = getEmptyDB();				    //get empty block index number from the function getEmptyDB()
	l_tFat.m_nNoOfBlocks = 1;

	if(l_tFat.m_nStartBlockNo == FALSE)						//if no empty block is present then display message & go back to main				
	{
		printf("\n Cannot Create the File..!! \n");
		strcpy(l_tERR.m_acFileName,l_tFat.m_acFileName);
		strcpy(l_tERR.m_acDetail,"Cannot Create the File..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}
	l_tFat.m_nAccessMode = 0;
	l_tFat.m_cDelimiter = '*';

	//read data from the user in a temporary file
	l_pFile=fopen(TEMP_FILE, "w");

	if(l_pFile == NULL)												//validation to check whether temporary file is opened
	{
		printf("\n\n Temp. File Cannot Be Loaded..!! \n");
		strcpy(l_tERR.m_acFileName,TEMP_FILE);
		strcpy(l_tERR.m_acDetail,"Cannot Be Loaded..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}
	else
	{
		printf("\n File is opened to write.. \n Enter the data.. \n Press (Ctrl + z) to save the file.. \n\n");
		fflush(stdin);
		while((l_cChar = getch()) != 26)
		{
			if(l_cChar == CARRIAGE_RETURN)								//if user presses Enter Key
			{
				printf("\n");
				fputc('\n', l_pFile);
				l_tFat.m_nFileSize++ ;
			}
			else if(l_cChar == BACKSPACE)								//if user presses Backspace Key
			{
				
				/*printing backspace to move cursor 1 pos back*/
				printf("\b");

				/*making the char invisible which is already on console*/
				printf("%c", SPACE);

				/*printing backspace to move cursor 1 pos back*/
				printf("\b");

				rewind(l_pFile);
				fseek(l_pFile,l_tFat.m_nFileSize-1,SEEK_SET);
				l_tFat.m_nFileSize--;
			}
			else														//for other characters
			{
				/* to add character in the file */
				putchar(l_cChar);
				fputc(l_cChar,l_pFile);
				l_tFat.m_nFileSize++ ;
			}
		}
		fputc('$',l_pFile);
		fclose(l_pFile);
	}

	

	//calculate no of blocks required to store the data

	if(l_tFat.m_nFileSize > DB_SIZE)
	{
		l_tFat.m_nNoOfBlocks=(l_tFat.m_nFileSize/DB_SIZE)+1;		
	}

	//If number of blocks is greater than the available space then display message and store it in the error log file
	if(l_tFat.m_nNoOfBlocks > availableSpace())
	{
		printf("\n Free Space Not Available..!! \n");
		printf("\n Cannot Create the File..!! \n");
		strcpy(l_tERR.m_acFileName,l_tFat.m_acFileName);
		strcpy(l_tERR.m_acDetail,"Free Space Not Available..!!Cannot Create the File..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}

	//for loop to go to the corresponding empty block index in data-block linked list
	for (l_pDbTemp=g_pDbStart;l_pDbTemp!=NULL;l_pDbTemp=l_pDbTemp->m_pNext)
	{
		if(l_pDbTemp->m_tDBlock.m_nIndex==l_tFat.m_nStartBlockNo)
		{
			break;
		}
	}

	//open temp file to move the data into data-block linked list
	l_pFile=fopen(TEMP_FILE, "r");

	if(l_pFile == NULL)													//validation to check whether temp file is opened
	{
		printf("\n\n Temp. File Cannot Be Loaded..!! \n");
		strcpy(l_tERR.m_acFileName,TEMP_FILE);
		strcpy(l_tERR.m_acDetail,"Cannot Be Loaded..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}
	else
	{
		//move data form file to data-blocks
		l_nCount=l_tFat.m_nNoOfBlocks;
		//while loop to enter data in multiple blocks
		while(l_nCount>0)													
		{
			l_nIndex=0;
			while((l_cChar = fgetc(l_pFile)) != '$' && l_nIndex<DB_SIZE)	//while loop to check end of data & data block size
			{
				l_pDbTemp->m_tDBlock.m_acData[l_nIndex]=l_cChar;
				l_nIndex++;
			}
			l_pDbTemp->m_tDBlock.m_nIsEmpty=0;
			l_nCount--;
			if(l_nCount==0)
			{
				l_pDbTemp->m_tDBlock.m_acData[l_nIndex]='$';
			}
			else
			{
				l_pDbTemp=l_pDbTemp->m_pNext;
			}
		}

		//close & remove temp file
		fclose(l_pFile);
		remove(TEMP_FILE);
	}

	//add timestamp
	strcpy(l_tFat.m_acCreationTime,ctime(&time1));
	strcpy(l_tFat.m_acModificationTime,ctime(&time1));

	//add entry to FAT table
	initializeFATTable(l_tFat);

	printf("\n\n File Created..!! \n");
	return TRUE;
}

/*
 * int listAllFiles()
 * Brief: funtion to list all files in the file system..
 * Params: No Parameters..
 * Return: Function returns TRUE after displaying file list..if list is empty it returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 03-01-2014
 * Change History: <change history>
 */
int listAllFiles()
{
	FNODE		*l_pFatNode;
	FAT_Type	l_tFat;

	l_pFatNode = g_pFatStart;

	//if file list is empty
	if(l_pFatNode == NULL)															
	{
		printf("\n No File Exist in the System..!! \n");
		return FALSE;
	}
	else							                     //if files exists display file list with its attributes
	{
		printf("\n\n File List: \n\n");
		printf("-----------------------------------------------------------------------------\n");
		while(l_pFatNode != NULL)
		{
			l_tFat = l_pFatNode->m_tFat;

			printf(" File Name \t: %s \n\n", l_tFat.m_acFileName);
			printf(" File size \t: %d bytes \n\n",l_tFat.m_nFileSize);

			//check access mode of the file
			if(l_tFat.m_nAccessMode == 1)                   
			{
				printf(" Access Mode \t: Read Only \n\n");
			}
			else
			{
				printf(" Access Mode \t: Read/Write \n\n");
			}
			printf(" Created On \t: %s \n", l_tFat.m_acCreationTime);
			printf(" Modified On \t: %s \n", l_tFat.m_acModificationTime);
			printf(" Starting Data Block Number \t: %d \n\n",l_tFat.m_nStartBlockNo);
			printf(" No. of Data Blocks Allocated \t: %d \n",l_tFat.m_nNoOfBlocks);
			printf("-----------------------------------------------------------------------------\n");
			l_pFatNode=l_pFatNode->m_pNext;
		}
		return TRUE;
	}
}

/*
 * int displayFile()
 * Brief: funtion to display a perticular file attributes & data stored in it..
 * Params: No Parameters..
 * Return: Function returns TRUE after displaying file attributes & contents else returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 03-01-2014
 * Change History: <change history>
 */
int displayFile()
{		
	FNODE		*l_pFatNode;
	DBNODE		*l_pDbTemp;
	int         l_nDBNo,l_nStartDB,l_niIndex,l_njIndex,l_nFlag;
	char		l_cFileName[FNAME_SIZE];

	//listing all files so that user can select a specific file from it
	l_nFlag=listAllFiles();

	if(l_nFlag == FALSE)												//if file list is empty return to main
	{
		return FALSE;
	}

	l_pFatNode=g_pFatStart;

	//take file name from the user
	printf("\n Enter the File Name : ");			
	fflush(stdin);
	gets(l_cFileName);


	//check whether file exists..

	while(l_pFatNode!=NULL)
	{
		if(strcmp(l_pFatNode->m_tFat.m_acFileName,l_cFileName)==0)
		{
			break;
		}
		else
		{
			l_pFatNode=l_pFatNode->m_pNext;
		}
	}
	if(l_pFatNode==NULL)												//if file does not exist
	{
		printf("\n File Does Not Exist..!! \n");
		return FALSE;
	}
	else																//if file exists display the file attirbutes
	{
		printf("\n %s File details are : \n",l_pFatNode->m_tFat.m_acFileName);
		printf("-----------------------------------------------------------------------------\n");
		printf(" File size \t: %d bytes \n\n",l_pFatNode->m_tFat.m_nFileSize);
		if(l_pFatNode->m_tFat.m_nAccessMode == 1)
		{
			printf(" Access Mode \t: Read Only \n\n");
		}
		else
		{
			printf(" Access Mode \t: Read/Write \n\n");
		}
		printf(" Crated On \t: %s \n",l_pFatNode->m_tFat.m_acCreationTime);
		printf(" Modified On \t: %s \n",l_pFatNode->m_tFat.m_acModificationTime);
		printf(" Starting Data Block Number \t: %d \n\n",l_pFatNode->m_tFat.m_nStartBlockNo);
		printf(" No. of Data Blocks Allocated \t: %d \n",l_pFatNode->m_tFat.m_nNoOfBlocks);
		printf("-----------------------------------------------------------------------------\n");
		printf(" File Contents are: \n\n");

		//displaying file contents

		l_nStartDB=l_pFatNode->m_tFat.m_nStartBlockNo;
		l_nDBNo=l_pFatNode->m_tFat.m_nNoOfBlocks;

		//for loop to find out corresponding data block in the data block linked list

		for (l_pDbTemp=g_pDbStart;l_pDbTemp!=NULL;l_pDbTemp=l_pDbTemp->m_pNext)
		{
			if(l_pDbTemp->m_tDBlock.m_nIndex==l_nStartDB)
			{
				break;
			}
		}


		if(l_pDbTemp->m_tDBlock.m_acData[0]=='$')
		{
			printf("\n No Data Found in the Given File..!! \n");
			return TRUE;
		}
		else
		{
			//for loop to display file contents from multiple data blocks
			for(l_njIndex=l_nDBNo;l_njIndex>0;l_njIndex--)
			{
				l_niIndex=0;
				while(l_pDbTemp->m_tDBlock.m_acData[l_niIndex] != '$' && l_niIndex<DB_SIZE)
				{	
					printf("%c",l_pDbTemp->m_tDBlock.m_acData[l_niIndex]);
					l_niIndex++;
				}
				l_pDbTemp=l_pDbTemp->m_pNext;
			}
			printf("\n\n End of File..!! \n");
			return TRUE;
		}
	}
}
/*
 * int deleteFile()
 * Brief: funtion to delete a file from the file system..
 * Params: No Parameters..
 * Return: Function returns TRUE after deleting the file else returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 03-01-2014
 * Change History: <change history>
 */
int deleteFile()
{
	char		l_cFileName[FNAME_SIZE],l_cChoice;
	int         l_nStartDB,l_DBNo,l_nIndex,l_nFlag;        
	FNODE		*l_pCurFatNode;
	FNODE		*l_pPrevFatNode;
	FNODE		*l_pFatNode;
	DBNODE		*l_pDbTemp;
	DB_Type		l_tDBlock;
	Error_Type  l_tERR;
	time        (&time1);

	l_pFatNode = g_pFatStart;
	l_pCurFatNode = g_pFatStart;
	l_pPrevFatNode = g_pFatStart;

	//listing all files so that user can select file from it
	l_nFlag=listAllFiles();

	if(l_nFlag == FALSE)													//if file list is empty return to main
	{
		return FALSE;
	}

	//take file name from the user
	printf("\n Enter the File Name : ");
	fflush(stdin);
	gets(l_cFileName);
	
	//check whether file exists..
	while(l_pCurFatNode!=NULL)
	{
		if(strcmp(l_pCurFatNode->m_tFat.m_acFileName,l_cFileName)==0)
		{
			break;
		}
		l_pPrevFatNode=l_pCurFatNode;
		l_pCurFatNode=l_pCurFatNode->m_pNext;
	}

	if(l_pCurFatNode==NULL)													//if file does not exist
	{
		printf("\n File Does Not Exist..!!\n");
		return FALSE;
	}

	if(l_pCurFatNode->m_tFat.m_nAccessMode == 1)				//if file exists but has read only access then it cannot be deleted
	{
		printf("\n File Cannot be Deleted as it is Read Only File..!! \n");
		strcpy(l_tERR.m_acFileName,l_pCurFatNode->m_tFat.m_acFileName);
		strcpy(l_tERR.m_acDetail,"File Cannot be Deleted as it is Read Only File..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}

	else																	//if file exists & has read/write access

	{
		printf("\n File Exists..!! \n");

		//ask for user confirmation

		printf("\n Do you wish to delete this file?(Y/N) : ");
		fflush(stdin);
		scanf("%c",&l_cChoice);

		if(l_cChoice == 'y' || l_cChoice == 'Y')
		{
			//making changes in data blocks
			
			l_nStartDB=l_pCurFatNode->m_tFat.m_nStartBlockNo;
			l_DBNo=l_pFatNode->m_tFat.m_nNoOfBlocks;
			
			//finding corresponding data blocks in data block linked list

			for (l_pDbTemp=g_pDbStart;l_pDbTemp!=NULL;l_pDbTemp=l_pDbTemp->m_pNext)
			{
				if(l_pDbTemp->m_tDBlock.m_nIndex==l_nStartDB)
				{
					break;
				}
			}

			//for loop to delete files with multiple data blocks
			for(l_nIndex=l_DBNo;l_nIndex>0;l_nIndex--)
			{
				l_pDbTemp->m_tDBlock.m_nIsEmpty=1;
				l_pDbTemp->m_tDBlock.m_acData[0]='$';
				l_pDbTemp=l_pDbTemp->m_pNext;
			}

			//deleting entry in FAT table

			if (l_pPrevFatNode == l_pCurFatNode)						//for the first file in FAT table linked list 
			{
				g_pFatStart = l_pCurFatNode->m_pNext;
			}
			else if (l_pCurFatNode->m_pNext == NULL)					//for last location in FAT table linked list
			{
				l_pPrevFatNode->m_pNext=l_pCurFatNode->m_pNext;
				l_pPrevFatNode->m_tFat.m_cDelimiter='*';
			}
			else														//for middle location in FAT table linked list
			{
				l_pPrevFatNode->m_pNext=l_pCurFatNode->m_pNext;
			}
			printf("\n\n File is Deleted..!! \n");	
			return TRUE;
		}
		else
		{
			printf("\n\n File Not Deleted..!! \n");	
			return FALSE;
		}
	}
}

/*
 * int changeName()
 * Brief: funtion to rename a file..
 * Params: No Parameters..
 * Return: Function returns TRUE after renaming a file else returns FALSE..
 * Authors: Neeraj Narkar
 * Date: 07-01-2014
 * Change History: <change history>
 */
int changeName()
{
	int			l_nFlag;
	char		l_cFileName[FNAME_SIZE];
	char		l_cNewFileName[FNAME_SIZE];
	FNODE		*l_pFatNode;
	Error_Type  l_tERR;

	time        (&time1);

	l_nFlag=listAllFiles();
	
	if(l_nFlag == FALSE)			//if file list is empty return to main
	{
		return FALSE;
	}

	l_pFatNode=g_pFatStart;

	//take file name from the user
	printf("\n Enter the File Name : ");
	fflush(stdin);
	gets(l_cFileName);

	while(l_pFatNode!=NULL)
	{
		if(strcmp(l_pFatNode->m_tFat.m_acFileName,l_cFileName)==0)			//to check whether file exists
		{
			break;
		}
		l_pFatNode=l_pFatNode->m_pNext;
	}

	if(l_pFatNode==NULL)													//if file does not exist
	{
		printf("\n File Does Not Exist..!! \n");
		return FALSE;
	}
	else
	{
		printf("\n Enter New File Name : ");
		fflush(stdin);
		gets(l_cNewFileName);

		if (l_pFatNode->m_tFat.m_nAccessMode == 1)							//if it is a read only file then name cannot be changed
		{
			printf("\n Read Only File..!! Cannot Change the Name..!! \n");
			strcpy(l_tERR.m_acFileName,l_pFatNode->m_tFat.m_acFileName);
			strcpy(l_tERR.m_acDetail,"Read Only File..!! Cannot Change the Name..!!");
			strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
			copyToErrorFile(l_tERR);
			return FALSE;
		}
		else																//if it is read/write file change the name
		{
			strcpy(l_pFatNode->m_tFat.m_acFileName,l_cNewFileName);    //filename changed

			//update timestamp

			strcpy(l_pFatNode->m_tFat.m_acModificationTime,ctime(&time1));
			printf("\n File Name Changed..!! \n");
			return TRUE;
		}
	}
}
/*
 * int appendToFile(char *l_cFileName)
 * Brief: funtion to append data to the file
 * Params: char *l_cFileName : contains file name to which user wants to append the contents
 * Return: Function returns TRUE appending data to the file else returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 04-01-2014
 * Change History: <change history>
 */
int appendToFile(char *l_cFileName)
{
	int			l_nStartDB,l_nDBNo,l_nIndex=0;     
	char		l_cChar;
	FILE		*l_pFile;
	FNODE		*l_pFatNode;
	DBNODE		*l_pDbTemp;
	Error_Type  l_tERR;
	time        (&time1);
	
    l_pFatNode=g_pFatStart;

	time(&time1);

	while(l_pFatNode!=NULL)																//To go to particular file in FAT table linked list
	{
		if(strcmp(l_pFatNode->m_tFat.m_acFileName,l_cFileName)==0)						
		{
			break;
		}
		l_pFatNode=l_pFatNode->m_pNext;
	}

	l_nStartDB=l_pFatNode->m_tFat.m_nStartBlockNo;										//To get starting block number
	l_nDBNo=l_pFatNode->m_tFat.m_nNoOfBlocks;											//To get number of blocks allocated to the file

	for (l_pDbTemp=g_pDbStart;l_pDbTemp!=NULL;l_pDbTemp=l_pDbTemp->m_pNext)				
	{
		if(l_pDbTemp->m_tDBlock.m_nIndex==l_nStartDB)
		{
			break;
		}
	}
	while(l_nDBNo-1!=0)																	//To get the last data block present in the file to append data
	{
		l_pDbTemp=l_pDbTemp->m_pNext;
	}

	l_pFile=fopen(TEMP_FILE, "w");

	if(l_pFile == NULL)																	//validation to check whether temp file is opened
	{
		printf("\n\n Temp. File Cannot Be Loaded..!! \n");
		strcpy(l_tERR.m_acFileName,TEMP_FILE);
		strcpy(l_tERR.m_acDetail,"Cannot Be Loaded..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}
	else
	{
		printf("\n File is opened to write.. \n Enter the data.. \n Press (Ctrl + z) to save the file.. \n\n");
		fflush(stdin);
		while((l_cChar = getch()) != 26)
		{
			if(l_cChar == CARRIAGE_RETURN)												//if user presses Enter Key
			{
				printf("\n");
				fputc('\n', l_pFile);
				l_pFatNode->m_tFat.m_nFileSize++ ;
			}
			else if(l_cChar == BACKSPACE)												//if user presses Backspace Key
			{
				/*printing backspace to move cursor 1 pos back*/
				printf("\b");

				/*making the char invisible which is already on console*/
				printf("%c", SPACE);

				/*printing backspace to move cursor 1 pos back*/
				printf("\b");

				rewind(l_pFile);
				fseek(l_pFile,l_pFatNode->m_tFat.m_nFileSize-1,SEEK_SET);
				l_pFatNode->m_tFat.m_nFileSize--;
			}
			else																		//for other characters
			{
				/* to add character in the file */
				putchar(l_cChar);
				fputc(l_cChar,l_pFile);
				l_pFatNode->m_tFat.m_nFileSize++ ;
			}
		}
		fputc('$',l_pFile);
		fclose(l_pFile);
	}

	for(l_nIndex=0;l_nIndex<DB_SIZE;l_nIndex++)										//Go to the last location to append the contents
	{
		if(l_pDbTemp->m_tDBlock.m_acData[l_nIndex] == '$')
		{
			break;
		}
	}

	//open the temp file to append the contents from file to data block
	l_pFile=fopen(TEMP_FILE, "r");

	if(l_pFile == NULL)																		//validation to check whether temp file is opened
	{
		printf("\n\n Temp. File Cannot Be Loaded..!! \n");
		strcpy(l_tERR.m_acFileName,TEMP_FILE);
		strcpy(l_tERR.m_acDetail,"Cannot Be Loaded..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}
	else
	{
		//append content into the data block
		while((l_cChar = fgetc(l_pFile)) != '$' && l_nIndex < DB_SIZE)
		{
			l_pDbTemp->m_tDBlock.m_acData[l_nIndex]=l_cChar;
			l_nIndex++;
		}
		l_pDbTemp->m_tDBlock.m_acData[l_nIndex]='$';
		
		//close & remove temp file
		fclose(l_pFile);
		remove(TEMP_FILE);
		
		//update timestamp
		strcpy(l_pFatNode->m_tFat.m_acModificationTime,ctime(&time1));
		printf("\n\n File is Modified Successfully..!! \n");
		return TRUE;
	}
}
/*
 * int overwriteFile(char *l_cFileName)
 * Brief: funtion to append data to the file
 * Params: char *l_cFileName : contains file name that user wants to overwrite
 * Return: Function returns TRUE overwrite data to the file else returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 04-01-2014
 * Change History: <change history>
 */
int overwriteFile(char *l_cFileName)
{ 
	char		l_cChar,l_cChoice;
	int         l_nDBNo,l_nCount,l_nIndex;
	FILE		*l_pFile;
	FNODE		*l_pFatNode;
	DBNODE		*l_pDbTemp;
	FAT_Type	 l_tFat;
	Error_Type  l_tERR;
	time        (&time1);
	
	l_pFatNode=g_pFatStart;

	time(&time1);

	l_pFile=fopen(TEMP_FILE, "w");

	if(l_pFile == NULL)											//validation to check whether temp file is opened
	{
		printf("\n\n Temp. File Cannot Be Loaded..!! \n");
		strcpy(l_tERR.m_acFileName,TEMP_FILE);
		strcpy(l_tERR.m_acDetail,"Cannot Be Loaded..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}
	else
	{
		printf("\n File is opened to write.. \n Enter the data.. \n Press (Ctrl + z) to save the file.. \n\n");
		fflush(stdin);
		while((l_cChar = getch()) != 26)
		{
			if(l_cChar == CARRIAGE_RETURN)												//if user presses Enter Key
			{
				printf("\n");
				fputc('\n', l_pFile);
			}
			else if(l_cChar == BACKSPACE)												//if user presses Backspace Key
			{
				/*printing backspace to move cursor 1 pos back*/
				printf("\b");

				/*making the char invisible which is already on console*/
				printf("%c", SPACE);

				/*printing backspace to move cursor 1 pos back*/
				printf("\b");

				rewind(l_pFile);
				fseek(l_pFile,l_pFatNode->m_tFat.m_nFileSize-1,SEEK_SET);
			}
			else																		//for other characters
			{
				/* to add character in the file */
				putchar(l_cChar);
				fputc(l_cChar,l_pFile);
			}
		}
		fputc('$',l_pFile);
		fclose(l_pFile);
	}

	printf("\n\n Are you sure you want to overwrite the file?(Y/N) : ");
	fflush(stdin);
	scanf("%c",&l_cChoice);

	if(l_cChoice=='Y' || l_cChoice=='y')
	{
		while(l_pFatNode!=NULL)
		{
			if(strcmp(l_pFatNode->m_tFat.m_acFileName,l_cFileName)==0)			//To look for the filename entered by the user
			{
				break;
			}
			l_pFatNode=l_pFatNode->m_pNext;
		}

		l_nDBNo=l_pFatNode->m_tFat.m_nNoOfBlocks;								//To get no of blocks allocated for the file

		if(l_nDBNo==1)														    //for file with single data block
		{
			for (l_pDbTemp=g_pDbStart;l_pDbTemp!=NULL;l_pDbTemp=l_pDbTemp->m_pNext)
			{
				if(l_pDbTemp->m_tDBlock.m_nIndex==l_pFatNode->m_tFat.m_nStartBlockNo)
				{
					break;
				}
			}

			l_pFile=fopen(TEMP_FILE, "r");

			if(l_pFile == NULL)												//validation to check whether temp file is opened
			{
				printf("\n\n Temp. File Cannot Be Loaded..!! \n");
				strcpy(l_tERR.m_acFileName,TEMP_FILE);
				strcpy(l_tERR.m_acDetail,"Cannot Be Loaded..!!");
				strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
				copyToErrorFile(l_tERR);
				printf("\n Press any key to continue..!!");
				getch();
				return FALSE;
			}
			else
			{
				//overwrite contents in the data block
				l_nIndex=0;
				l_pFatNode->m_tFat.m_nFileSize=0;
				while((l_cChar = fgetc(l_pFile)) != '$')
				{
					l_pDbTemp->m_tDBlock.m_acData[l_nIndex]=l_cChar;
					l_nIndex++;
					l_pFatNode->m_tFat.m_nFileSize++;
				}
				l_pDbTemp->m_tDBlock.m_acData[l_nIndex]='$';

				//update timestamp
				strcpy(l_pFatNode->m_tFat.m_acModificationTime,ctime(&time1));

				//close & remove temp file
				fclose(l_pFile);
				remove(TEMP_FILE);
				printf("\n\n File is Modified Successfully..!! \n");
				return TRUE;
			}
		}
		else																				//for file with multiple data blocks
		{
			for (l_pDbTemp=g_pDbStart;l_pDbTemp!=NULL;l_pDbTemp=l_pDbTemp->m_pNext)
			{
				if(l_pDbTemp->m_tDBlock.m_nIndex==l_pFatNode->m_tFat.m_nStartBlockNo)
				{
					break;
				}
			}
			l_pFile=fopen(TEMP_FILE, "r");

			if(l_pFile == NULL)																//validation to check whether temp file is opened
			{
				printf("\n\n Temp. File Cannot Be Loaded..!! \n");
				strcpy(l_tERR.m_acFileName,TEMP_FILE);
				strcpy(l_tERR.m_acDetail,"Cannot Be Loaded..!!");
				strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
				copyToErrorFile(l_tERR);
				printf("\n Press any key to continue..!!");
				getch();
				return FALSE;
			}
			else
			{
				//overwrite contents to the file
				l_nCount=l_pFatNode->m_tFat.m_nNoOfBlocks;
				while(l_nCount>0)
				{
					l_nIndex=0;
					while((l_cChar = fgetc(l_pFile)) != '$' || l_nIndex<DB_SIZE)
					{
						l_pDbTemp->m_tDBlock.m_acData[l_nIndex]=l_cChar;
						l_nIndex++;
					}
					l_pDbTemp->m_tDBlock.m_nIsEmpty=0;
					l_nCount--;
					if(l_nCount==0)
					{
						l_pDbTemp->m_tDBlock.m_acData[l_nIndex]='$';
					}
					else
					{
						l_pDbTemp=l_pDbTemp->m_pNext;
					}
				}

				//update timestamp
				strcpy(l_pFatNode->m_tFat.m_acModificationTime,ctime(&time1));
				
				//close & remove temp file
				fclose(l_pFile);
				remove(TEMP_FILE);
				printf("\n\n File is Modified Successfully..!! \n");
				return TRUE;
			}
		}
	}
	else
	{
		printf("\n\n  File Contents are Not Modified..!! \n");
		return FALSE;
	}
}
/*
 * int changeContent()
 * Brief: funtion to change file contents..
 * Params: No parameters..
 * Return: Function returns TRUE after successful execution else returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 04-01-2014
 * Change History: <change history>
 */
int changeContent()
{
	char		l_cFileName[FNAME_SIZE];
	int			l_nChoice=0,l_nFlag;    
	FNODE		*l_pFatNode;
	Error_Type  l_tERR;
	time        (&time1);

	//listing all files so that user can select file from it
	l_nFlag=listAllFiles();

	if(l_nFlag == FALSE)			//if file list is empty return to main
	{
		return FALSE;
	}

	l_pFatNode=g_pFatStart;

	//take file name from the user
	printf("\n Enter the File Name : ");
	fflush(stdin);
	gets(l_cFileName);

	while(l_pFatNode!=NULL)
	{
		if(strcmp(l_pFatNode->m_tFat.m_acFileName,l_cFileName)==0)			//to check whether file exists
		{
			break;
		}
		l_pFatNode=l_pFatNode->m_pNext;
	}

	if(l_pFatNode==NULL)													//if file does not exist
	{
		printf("\n File Does Not Exist..!! \n");
		return FALSE;
	}
	else
	{
		printf("\n File Found..!! \n");
		if(l_pFatNode->m_tFat.m_nAccessMode == 0)							//To check if the access mode is read/write.
		{
			system("cls");
			printf("\n********************* Modify File *********************\n");
			printf("\n 1. Append \n");
			printf("\n 2. Overwrite \n");
			printf("\n 3. Go Back \n");
			printf("\n\n Enter your choice : ");
			scanf("%d",&l_nChoice);

			switch(l_nChoice)
			{
				case 1:
						//Append();
						appendToFile(l_cFileName);
						break;

				case 2:
						//Overwrite();
						overwriteFile(l_cFileName);
						break;

				case 3:
						//go back
						break;
						
				default:printf("\n Enter a valid option..!! \n");
						printf("\n Press any key to continue..!!");
						getch();
						break;
			}
			return TRUE;

		}
		else
		{
			printf("\n File Cannot be Edited as it is Read Only File..!! \n");
			strcpy(l_tERR.m_acFileName,l_pFatNode->m_tFat.m_acFileName);
			strcpy(l_tERR.m_acDetail,"File Cannot be Edited as it is Read Only File..!!");
			strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
			copyToErrorFile(l_tERR);
			return FALSE;
		}
	}
}

/*
 * int changeFileMode()
 * Brief: funtion to change file access permissions..
 * Params: No Parameters..
 * Return: Function returns TRUE after changing the file permissions else returns FALSE..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 03-01-2014
 * Change History: <change history>
 */
int changeFileMode()
{
	char		l_cChar;
	char		l_cFileName[FNAME_SIZE];
	int			l_nFlag;
	FNODE		*l_pFatNode;
	Error_Type  l_tERR;
	time        (&time1);
	
	//listing all files so that user can select file from it
	l_nFlag=listAllFiles();
	
	if(l_nFlag == FALSE)			//if file list is empty return to main
	{
		return FALSE;
	}

	l_pFatNode=g_pFatStart;

	//taking file name form the user
	printf("\n Enter the File Name : ");
	fflush(stdin);
	gets(l_cFileName);

	//check whether file exists
	while(l_pFatNode!=NULL)
	{
		if(strcmp(l_pFatNode->m_tFat.m_acFileName,l_cFileName)==0)
		{
			break;
		}
		else
			l_pFatNode=l_pFatNode->m_pNext;
	}

	if(l_pFatNode==NULL)								//if file does not exist
	{
		printf("\n File Does Not Exist..!! \n");
		strcpy(l_tERR.m_acFileName,l_cFileName);
		strcpy(l_tERR.m_acDetail,"File Does Not Exist..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		return FALSE;
	}
	else												//if file exists
	{

		//display current mode

		if(l_pFatNode->m_tFat.m_nAccessMode==0)
		{
			printf("\n Current File Mode : Read/Write \n");
		}
		else
		{
			printf("\n Current File Mode : Read Only \n");
		}
		do
		{
			//ask user to enter new mode
			printf("\n Enter New Mode (R/W): ");
			fflush(stdin);
			scanf("%c", &l_cChar);

		}while(!(l_cChar == 'r' || l_cChar == 'w' || l_cChar == 'R' || l_cChar == 'W'));


		//change the file mode
		if(l_cChar == 'r' || l_cChar == 'R')
		{
			l_pFatNode->m_tFat.m_nAccessMode = 1;
		}
		if(l_cChar == 'w' || l_cChar == 'W')
		{
			l_pFatNode->m_tFat.m_nAccessMode = 0;
		}

		//update timestamp
		strcpy(l_pFatNode->m_tFat.m_acModificationTime,ctime(&time1));
		printf("\n File Access Mode is Changed..!! \n");
		
		//display new file mode
		if(l_pFatNode->m_tFat.m_nAccessMode==0)
		{
			printf("\n Current File Mode : Read/Write \n");
		}
		else
		{
			printf("\n Current File Mode : Read Only \n");
		}
		return TRUE;
	}
}

/*
 * int modifyFile()
 * Brief: funtion modify file..
			function inturn calls two functions depending upon user input to change
				1)file contents
				2)file permissions
 * Params: No Parameters..
 * Return: Function returns TRUE after successful execution..
 * Authors: Dhwani Patel,Sneha Nair
 * Date: 04-01-2014
 * Change History: <change history>
 */
int modifyFile()
{
	int l_nOption=0;

	//display modify options
	do
	{
		system("cls");
		printf("\n********************* Modify File *********************\n");
		printf("\n 1. Rename File ");
		printf("\n 2. Change File Contents ");
		printf("\n 3. Change Access Mode ");
		printf("\n 4. Go Back ");

		//ask for user input
		printf("\n\n Enter your Option: ");
		fflush(stdin);
		scanf("%d", &l_nOption);
		switch(l_nOption)
		{
			case 1:	
					//Function to Change File Name
					changeName();
					printf("\n Press any key to continue..!!");
					getch();
					break;

			case 2:
					//Function to Change File Content
					changeContent();
					printf("\n Press any key to continue..!!");
					getch();
					break;
			case 3:
					//Function to Change Access Mode
					changeFileMode();
					printf("\n Press any key to continue..!!");
					getch();
					break;
			case 4:
					//go back
					break;
			default:
					//if user enters wrong option
					printf("\n Enter a valid option..!! \n");
					printf("\n Press any key to continue..!!");
					getch();
					break;
		}
	}while (l_nOption!=4);
	return TRUE;
}

