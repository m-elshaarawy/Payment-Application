
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Terminal.h>
 *       Module:  terminal
 *  Description:  terminal header file
 *       author: mohamed elshaarawy      
 *********************************************************************************************************************/
#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "../card/Card.h"

/*********************************config*********************************/
#define USE_MAX       1          // ( 1 ) to use MAX_AMOUNT ( 0 ) to not 
#define MAX_AMOUNT    20000      // transaction limit
/************************************************************************/

/* data typs and structs */

typedef struct {
 unsigned int transAmount ;
 unsigned int maxTransAmount;
 char transDate[6];

}ST_terminalData_t;

typedef enum {

 INVALID_DATA,
 EXPIRED_CARD,
 EXCEED_LIMIT,
 DONE
}EN_terminalError_t;


/* Function prototypes */

EN_terminalError_t getTransactionDate(ST_terminalData_t* data);
EN_terminalError_t isCardExpired(ST_terminalData_t *data , ST_cardData_t card);
EN_terminalError_t getTransactionAmount(ST_terminalData_t* data);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *data);
EN_terminalError_t setMaxAmount(ST_terminalData_t* data);

#endif // TERMINAL_H_