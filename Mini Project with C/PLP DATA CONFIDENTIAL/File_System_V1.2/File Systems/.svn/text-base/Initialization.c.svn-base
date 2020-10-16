/****************************<File Header>**********************************/
/*!
@File: Initialization.c
@brief Abstract:This file includes the functions required to initialize the file system.
@Description: This file has all the functions which are required to initialize the File System.
These functions are- check file system exits or not,create file system if it does not exist,data blocks 
creation,copy the data blocks linked list to file,FAT table initialization,copy FAT table to file,load FAT
table and the data blocks from file if the file system already exists . 
@Author: Neeraj Narkar
@Date: 02-01-2014
@Change History: <change history>
*/
/****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "Initialization.h"

/*
 * int checkFileSystem()
 * Brief: funtion to check whether file system exists..
 * Params: No Parameters..
 * Return: Function returns TRUE if file system exists else returns FALSE..
 * Authors: Neeraj Narkar
 * Date: 02-01-2014
 * Change History: <change history>
 */
int checkFileSystem()
{
	FILE *l_pFile;								//file pointer for file system

	l_pFile = fopen(FILE_SYSTEM, "r");			//opening file system root file

	//check whether file system exists
	if(l_pFile == NULL)
	{
		printf("\n\n File System Does Not Exist..!! \n");
		printf("\n Press any key to continue..!!");
		getch();
		return FALSE;
	}
	else
	{
		fclose(l_pFile);
		printf("\n\n File System Exists..!! \n");
		printf("\n Press any key to continue..!!");
		getch();
		return TRUE;
	}
}

/*
 * void createFileSystem()
 * Brief: funtion to create file system having root file of 10MB..
 * Params: No Parameters..
 * Return: Function returns TRUE if file system is created else returns FALSE..
 * Authors: Neeraj Narkar
 * Date: 02-01-2014
 * Change History: <change history>
 */
int createFileSystem()
{
	FILE       *l_pFile;
	Error_Type l_tERR;
	time       (&time1);
	
	l_pFile = fopen(FILE_SYSTEM, "w");					//opening file system root file

	if(l_pFile == NULL)
	{
		printf("\n\n File System Cannot Be Created..!! \n");
		strcpy(l_tERR.m_acFileName,FILE_SYSTEM);
		strcpy(l_tERR.m_acDetail,"File System Cannot Be Created..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		printf("\n Press any key to continue..!!");
		getch();
		return FALSE;
	}
	else
	{
		fseek(l_pFile,(FS_SIZE)-1,SEEK_SET);			//Initializing the file system to 10MB
		fprintf(l_pFile,"%c",'$');
		fclose(l_pFile);
		printf("\n\n File System Created..!! \n");
		printf("\n Press any key to continue..!!");
		getch();
		return TRUE;
	}
}

/*
 * void initializeDataBlocks()
 * Brief: funtion to create a linklist of data-blocks of 1KB
 * Params: No Parameters..
 * Return: Function returns TRUE if data blocks linklist is created..
 * Authors: Neeraj Narkar
 * Date: 03-01-2014
 * Change History: <change history>
 */
int initializeDataBlocks()
{
	int l_nDbCount;
	int l_nIndex;

	l_nDbCount = (FS_SIZE-DB_START)/sizeof(DB_Type);						//counting number of data blocks that can be created 

	for(l_nIndex = 1 ; l_nIndex <= l_nDbCount ; l_nIndex++)				    //loop to create linked list of data-blocks
	{
		DBNODE *l_pDbNode;
		l_pDbNode = (DBNODE*)malloc(sizeof(DBNODE));

		l_pDbNode->m_tDBlock.m_nIndex = l_nIndex;
		l_pDbNode->m_tDBlock.m_nIsEmpty=1;

		if(g_pDbEnd == NULL)
		{
			g_pDbStart = l_pDbNode;
			l_pDbNode->m_pNext = NULL;
		}
		else
		{
			g_pDbEnd->m_pNext = l_pDbNode;
			l_pDbNode->m_pNext = NULL;
		}
		g_pDbEnd = l_pDbNode;
	}
	system("cls");
	printf("\n\n Number of data blocks created : %d \n",l_nDbCount);
	printf("\n Press any key to continue..!!");
	getch();
	return  TRUE;
}
/*
 * void copyDBToFile()
 * Brief: funtion to transfer linklist of data-blocks into file system
 * Params: No Parameters..
 * Return: Function returns TRUE if data block linked list is copied to the file else returns FALSE..
 * Authors: Neeraj Narkar
 * Date: 03-01-2014
 * Change History: <change history>
 */
int copyDBToFile()
{
	DB_Type    l_tDBlock;
	DBNODE	   *l_pDbNode;
	FILE	   *l_pFile;
	Error_Type l_tERR;
	time       (&time1);

	l_pFile = fopen(FILE_SYSTEM,"rb+");

	if(l_pFile == NULL)											//validation to check whether file system exists
	{
		printf("\n\n File System Cannot Be Loaded..!! \n");
		strcpy(l_tERR.m_acFileName,FILE_SYSTEM);
		strcpy(l_tERR.m_acDetail,"File System Cannot Be Loaded..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		printf("\n Press any key to continue..!!");
		getch();
		return FALSE;
	}
	else														//if file is open then copy data-block linked list to file
	{
		system("cls");
		printf("\n\n Copying Data Blocks to the File System..!! \n");
		fseek(l_pFile, DB_START+1, SEEK_SET);
		if(g_pDbStart == NULL)
		{
			fputc('*', l_pFile);
		}

		l_pDbNode = g_pDbStart;

		while(l_pDbNode != NULL)	
		{	
			l_tDBlock = l_pDbNode->m_tDBlock;
			fwrite(&l_tDBlock, sizeof(l_tDBlock), 1, l_pFile);
			l_pDbNode = l_pDbNode->m_pNext;
		}
		fclose(l_pFile);
		printf("\n\n Data Blocks are Copied to the File System..!! \n");
		printf("\n Press any key to continue..!!");
		getch();
		return TRUE;
	}
}
/*
 * void initializeDBList(DB_Type f_tDBlock)
 * Brief: funtion to create a linked list of data-blocks of 1KB
 * Params: f_tDBlock : DB_Type structure variable that holds Index Number to create a single node..
 * Return: Function returns TRUE if single node in data block linked list is created..
 * Authors: Neeraj Narkar
 * Date: 03-01-2014
 * Change History: <change history>
 */
int initializeDBList(DB_Type f_tDBlock)
{
	DBNODE *l_pDbNode;

	l_pDbNode = (DBNODE*)malloc(sizeof(DBNODE));				//creation of a single node for data-block linked list

	l_pDbNode->m_tDBlock = f_tDBlock;							//copy contents of passed parameter to the created node

	if(g_pDbStart == NULL)										//add the created node to the linked list
	{
		g_pDbStart = l_pDbNode;
		l_pDbNode->m_pNext = NULL;
	}
	else
	{
		g_pDbEnd->m_pNext = l_pDbNode;
		l_pDbNode->m_pNext = NULL;
	}
	g_pDbEnd = l_pDbNode;		
	return TRUE;
}

/*
 * void loadDB()
 * Brief: funtion to transfer details of data-blocks into a linked list
 * Params: No Parameters..
 * Return: Function returns TRUE if datablock linked list is loaded from the file else returns FALSE..
 * Authors: Neeraj Narkar
 * Date: 03-01-2014
 * Change History: <change history>
 */
int loadDB()
{
	int        l_nDbCount,l_nCount=0;
	FILE	   *l_pFile;
	DB_Type    l_tDBlock;
	Error_Type l_tERR;
	time       (&time1);

	l_nDbCount = (FS_SIZE-DB_START)/sizeof(DB_Type);

	l_pFile = fopen(FILE_SYSTEM, "rb");
	if(l_pFile == NULL)											//validation to check whether file system exists
	{
		printf("\n\n File System Cannot Be Loaded..!! \n");
		strcpy(l_tERR.m_acFileName,FILE_SYSTEM);
		strcpy(l_tERR.m_acDetail,"File System Cannot Be Loaded..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		printf("\n Press any key to continue..!!");
		getch();
		return FALSE;
	}
	else														//if file is open then create a linked list of data-blocks
	{
		system("cls");
		printf("\n\n Loading Data Blocks from the File System..!! \n");
		fseek(l_pFile, DB_START+1, SEEK_SET);
		do
		{
			fread(&l_tDBlock,sizeof(l_tDBlock),1,l_pFile);
			initializeDBList(l_tDBlock);
			l_nCount++;
		}while(l_nCount < l_nDbCount);
		fclose(l_pFile);
		printf("\n\n Data Blocks are Loaded from the File System..!! \n");
		printf("\n Press any key to continue..!!");
		getch();
		return TRUE;
	}
}

/*
 * void copyFATToFile()
 * Brief: funtion to transfer FAT table linked list into a file
 * Params: No Parameters..
 * Return: Function returns TRUE if FAT table linked list is copied to the file else returns FALSE..
 * Authors: Neeraj Narkar
 * Date: 02-01-2014
 * Change History: <change history>
 */
int copyFATToFile()
{
	FAT_Type	l_tFat;
	FILE		*l_pFile;
	FNODE		*l_pFatNode;
	Error_Type  l_tERR;
	time        (&time1);

	l_pFile = fopen(FILE_SYSTEM,"rb+");
	
	if(l_pFile == NULL)											//validation to check whether file system exists
	{
		printf("\n\n File System Cannot Be Loaded..!! \n");
		strcpy(l_tERR.m_acFileName,FILE_SYSTEM);
		strcpy(l_tERR.m_acDetail,"File System Cannot Be Loaded..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		printf("\n Press any key to continue..!!");
		getch();
		return FALSE;
	}
	
	else														//if file is open then copy fat table to file system
	{
		system("cls");
		printf("\n\n Copying FAT Table to the File System..!! \n");
		fseek(l_pFile, 0, SEEK_SET);
		if(g_pFatStart == NULL)
		{
			fputc('*', l_pFile);
		}

		l_pFatNode = g_pFatStart;

		while(l_pFatNode != NULL)	
		{	
			l_tFat = l_pFatNode->m_tFat;
			fwrite(&l_tFat, sizeof(l_tFat), 1, l_pFile);
			l_pFatNode = l_pFatNode->m_pNext;
		}
		fclose(l_pFile);
		printf("\n\n FAT Table is Copied to the File System..!! \n");
		printf("\n Press any key to continue..!!");
		getch();
		return TRUE;
	}
}

/*
 * void initializeFATTable(FAT_Type f_tFat)
 * Brief: funtion to create a single node of FAT table linked list
 * Params: f_tFat : FAT_Type structure variable that holds the details of the node to be created
 * Return: Function returns TRUE if single node in FAT table linked list is created..
 * Authors: Neeraj Narkar
 * Date: 02-01-2014
 * Change History: <change history>
 */
int initializeFATTable(FAT_Type f_tFat)
{
	FNODE	*l_pFatNode;

	l_pFatNode = (FNODE*)malloc(sizeof(FNODE));							//creating a node of FAT table linked list

	l_pFatNode->m_tFat = f_tFat;										//copy contents of passed parameter to the created node

	if(g_pFatStart == NULL)												//add created node to the linked list
	{
		g_pFatStart = l_pFatNode;
		l_pFatNode->m_pNext = NULL;
	}
	else
	{
		g_pFatEnd->m_tFat.m_cDelimiter = '|';
		g_pFatEnd->m_pNext = l_pFatNode;
		l_pFatNode->m_pNext = NULL;
	}
	g_pFatEnd = l_pFatNode;	
	return TRUE;
}
/*
 * void loadFATTable()
 * Brief: funtion to transfer FAT table details from the file system to the linked list
 * Params: No Parameter..
 * Return: Function returns TRUE if FAT table linked list is loaded from the file else returns FALSE..
 * Authors: Neeraj Narkar
 * Date: 02-01-2014
 * Change History: <change history>
 */
int loadFATTable()
{
	FILE		*l_pFile;
	FAT_Type	l_tFat;
	Error_Type  l_tERR;
	time        (&time1);

	l_pFile = fopen(FILE_SYSTEM,"rb");

	if(l_pFile == NULL)											//validation to check whether file system exists
	{
		printf("\n\n File System Cannot Be Loaded..!! \n");
		strcpy(l_tERR.m_acFileName,FILE_SYSTEM);
		strcpy(l_tERR.m_acDetail,"File System Cannot Be Loaded..!!");
		strcpy(l_tERR.m_acOccuringTime,ctime(&time1));
		copyToErrorFile(l_tERR);
		printf("\n Press any key to continue..!!");
		getch();
		return FALSE;
	}
	else														//if file is open then create linked list of FAT Table
	{
		system("cls");
		if(fgetc(l_pFile) == '*')
		{
			printf("\n\n Empty FAT Table..!! \n");
			printf("\n Press any key to continue..!!");
			getch();
			return TRUE;
		}
		else
		{
			printf("\n\n Loading FAT Table from the File System..!! \n");
			fseek(l_pFile, 0, SEEK_SET);
			do
			{
				fread(&l_tFat,sizeof(l_tFat),1,l_pFile);
				initializeFATTable(l_tFat);
			}while(l_tFat.m_cDelimiter != '*');
			fclose(l_pFile);
			printf("\n\n FAT Table is Loaded from the File System..!! \n");
			printf("\n Press any key to continue..!!");
			getch();
			return TRUE;
		}
		
	}
}
