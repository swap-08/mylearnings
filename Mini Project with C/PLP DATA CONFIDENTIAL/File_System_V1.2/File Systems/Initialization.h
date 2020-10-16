/****************************<File Header>**********************************/
/*!
@File: Initialization.h
@brief Abstract:This header file contains all the file system initialization
function prototypes.
@Author: Neeraj Narkar
@Date: 02-01-2014
@Change History: <change history>
*/
/****************************************************************************/

#include "SystemDefinitions.h"

/*
 * int checkFileSystem()
 * Brief: funtion to check whether file system exists..
 * Params: No Parameters..
 * Return: Function returns TRUE if file system exists else returns FALSE.. 
 */
int checkFileSystem();

/*
 * void createFileSystem()
 * Brief: funtion to create file system having root file of 10MB..
 * Params: No Parameters..
 * Return: Function returns TRUE if file system is created else returns FALSE.. 
 */
int createFileSystem();

/*
 * void copyDBToFile()
 * Brief: funtion to transfer linklist of data-blocks into file system
 * Params: No Parameters..
 * Return: Function returns TRUE if data block linklist is copied to the file else returns FALSE..
 */
int copyDBToFile();

/*
 * void initializeDBList(DB_Type f_tDBlock)
 * Brief: funtion to create a linklist of data-blocks of 1KB
 * Params: f_tDBlock : DB_Type structure variable that holds Index Number to create a single node..
 * Return: Function returns TRUE if single node in data block linklist is created..
 */
int initializeDBList(DB_Type f_tDBlock);

/*
 * void loadDB()
 * Brief: funtion to transfer details of data-blocks into a linklist
 * Params: No Parameters..
 * Return: Function returns TRUE if datablock linklist is loaded from the file else returns FALSE..
 */
int loadDB();

/*
 * void copyFATToFile()
 * Brief: funtion to transfer FAT table linklist into a file
 * Params: No Parameters..
 * Return: Function returns TRUE if FAT table linklist is copied to the file else returns FALSE..
 */
int copyFATToFile();

/*
 * void initializeFATTable(FAT_Type f_tFat)
 * Brief: funtion to create a single node of FAT table linklist
 * Params: f_tFat : FAT_Type structure variable that holds the details of the node to be created
 * Return: Function returns TRUE if single node in FAT table linklist is created..
 */
int initializeFATTable(FAT_Type f_tFat);

/*
 * void loadFATTable()
 * Brief: funtion to transfer FAT table details from the file system to the linklist
 * Params: No Parameter..
 * Return: Function returns TRUE if FAT table linklist is loaded from the file else returns FALSE..
 */
int loadFATTable();
