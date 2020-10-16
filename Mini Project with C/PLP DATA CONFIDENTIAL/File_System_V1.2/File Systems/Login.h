/****************************<File Header>**********************************/
/*!
@File: Login.h
@brief Abstract:This header file contains all the file system login function
prototypes.
@Author: Swapnil Kadam
@Date: 09-01-2014
@Change History: <change history>
*/
/****************************************************************************/

#include "SystemDefinitions.h"


/*
 * void add_User()
 * Brief: funtion to add users to the file system
 * Params: No Parameter..
 * Return: void..
 */
void add_User();

/*
 * void admin_Login()
 * Brief: funtion for authentication of admin 
 * Params: No Parameter..
 * Return: Function returns TRUE if FAT table linklist is loaded from the file else returns FALSE..
 */
int admin_Login();

/*
 * void user_Login()
 * Brief: funtion for authentication of users
 * Params: No Parameter..
 * Return: Function returns TRUE if FAT table linklist is loaded from the file else returns FALSE..
 */
int user_Login();

