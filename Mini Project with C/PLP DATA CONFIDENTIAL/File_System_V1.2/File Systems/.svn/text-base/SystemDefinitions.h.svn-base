/****************************<File Header>**********************************/
/*!
@File: SystemDefinitions.h
@brief Abstract: This file includes structure definitions a
@Author: Neeraj Narkar
@Date: 02-01-2014
@Change History: <change history>
*/
/****************************************************************************/

#pragma once
#define FILE_SYSTEM			"filesystem.lst"
#define TEMP_FILE			"temp.lst"
#define ERROR_LOG_FILE		"error_log_file.lst"
#define USER_FILE			"userlogin.lst"
#define ADMIN_USERNAME		"ADMIN"					//login credentials for admin
#define ADMIN_PASSWORD		"123"					//password for admin
#define TRUE				1
#define FALSE				0
#define FS_SIZE				10485760				//file system size (1024*1024*10 bytes) = 10MB
#define DB_SIZE				4096					//data block size (1024KB)
#define TIME_SIZE			30						//timestamp size (DAY MON DD HH:MM:SS YYYY)
#define FNAME_SIZE			255						//file name length (255 characters)
#define DB_START			33600					//data block size
#define DATA_SIZE			10448784				//data size
#define MAX_FILES			100						//maximum file capacity
#define ERROR_SIZE			100						//Error Description Length
#define CARRIAGE_RETURN		13						//ASCII value of enter
#define BACKSPACE			8						//ASCII value of backspace
#define SPACE				32						//ASCII value of space
#define USER_LENGTH			15						//username length
#define TEMP_LENGTH			200						//temporary length for username and password

/*!
@Struct: USER_LOGIN
@brief Abstract: This structure includes the variables required login of multiple users.
@Description: The variables used in this structure are used to store the user name and user password
@Change History: <change history>
*/
typedef struct
{
	char l_acUserName[USER_LENGTH];
	char l_acPassword[USER_LENGTH];
}USER_LOGIN;

/*!
@Struct: FAT_Type
@brief Abstract: This structure includes the variables required to store the FAT table details for each file.
@Description: The variables used in this structure are used to store the file name,file size,creation and modification
time,address of starting data block,numbers of blocks used by the file,access mode of file and a delimiter to mark the end of file.
@Change History: <change history>
*/
typedef struct
{
	char	m_acFileName[FNAME_SIZE];			//name of file
	int		m_nFileSize;						//size of file
	char	m_acCreationTime[TIME_SIZE];		//file creation time
	char	m_acModificationTime[TIME_SIZE];	//file modification time
	int		m_nStartBlockNo;					//starting data block index number
	int		m_nNoOfBlocks;						//no of blocks allocated
	int		m_nAccessMode;						//access mode for file (0:read/write, 1:read)
	char	m_cDelimiter;						//FAT delimiter 
}FAT_Type;
/*!
@Struct: FNODE
@brief Abstract: This structure stores a FAT_Type variable as a node and a pointer to the next node.
@Description: this structure contains a variable which is of type struct FAT_Type which stores the 
data of the FAT table and a pointer which points to the next location of the table.
@Change History: <change history>
*/
typedef struct
{
	FAT_Type			m_tFat;					//node containing FAT detail
	struct FAT_NODE_T	*m_pNext;				//pointer to next FAT entry
}FNODE;

FNODE	*g_pFatStart, *g_pFatEnd;


/*!
@Struct: DB_Type
@brief Abstract: This structure includes the variables required to store the data block details for each file.
@Description: Every data block has an index number associated with it,a variable of type int to check whether the block
is empty or not and a character array to store tha data entered by the user.
@Change History: <change history>
*/
typedef struct
{
	int		m_nIndex;							//index number of data block
	int		m_nIsEmpty;							//number to check whether the block is empty (1:empty, 0:full)
	char	m_acData[DB_SIZE];					//character array to store the data of size 4kb
}DB_Type;

/*!
@Struct: DBNODE
@brief Abstract: This structure stores a DB_Type variable as a node and a pointer to the next node.
@Description: This structure contains a variable which is of type struct DB_Type which stores the 
data of the each data block and a pointer which points to the next location of the data block.
@Change History: <change history>
*/
typedef struct
{
	DB_Type				m_tDBlock;				//node containing Data Block detail
	struct DB_NODE_T	*m_pNext;				//pointer to next Data Block entry
}DBNODE;

DBNODE	*g_pDbStart, *g_pDbEnd;


/*!
@Struct: Error_Type
@brief Abstract: This structure includes the variables required to store the error information.
@Description: This structure includes the variables required to store the error messages displayed whenever 
an error is encountered,the file name for which it was encountered and the time it occurred.
@Change History: <change history>
*/

typedef struct
{
	char	m_acFileName [FNAME_SIZE];			//file name
	char	m_acOccuringTime[TIME_SIZE];		//occuring time of error
	char	m_acDetail[ERROR_SIZE];				//error detail
}Error_Type;


//The time_t datatype is a data type in the  C library defined for storing system time values. 

time_t time1;

