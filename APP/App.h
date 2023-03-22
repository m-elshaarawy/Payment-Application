
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <App.h>
 *       Module:  APP
 *  Description:  Application header file
 *       author: mohamed elshaarawy      
 *********************************************************************************************************************/
#ifndef APP_H_
#define APP_H_

#include"../server/Server.h"

/* GLOBAL DATA PROTOTYPES */
extern ST_accountDatabase_t accountDatabase[6];
extern ST_transDatabase_t transDatabase[200];

/* function prototype */
void appStart(void);

#endif // APP_H_