

#ifndef SERVER_H_
#define SERVER_H_

#include "../terminal/Terminal.h"

/* data typs and structs */

typedef enum {

  ACTIVE,
  BLOCKED,
  INVALID_ACCOUNT

}EN_accountState_t;

typedef enum {

  VALID_TRANS,
  INVALID_TRANS,
  AVAILABLE,
  UNAVAILABLE

}EN_transactionState_t;


typedef struct {
    
    ST_cardData_t card_data;
    ST_terminalData_t term_data;

}ST_transactionData_t;

typedef struct {
    
    unsigned int trans_number;
    ST_transactionData_t trans_data;

}ST_transDatabase_t;

typedef struct {
    
    char accountName[25];
    char server_PAN[17];
    EN_accountState_t account_state;
    unsigned int funds;

}ST_accountDatabase_t;



/* Function prototypes */

EN_transactionState_t receiveTransactionData(ST_transactionData_t* transData,ST_cardData_t* cardData,ST_terminalData_t* termData);
EN_accountState_t isValidAccount(ST_transactionData_t* transData,ST_accountDatabase_t* accountData);
EN_transactionState_t isAmountAvailable(ST_transactionData_t* transData,ST_accountDatabase_t* accountData);
EN_transactionState_t saveTransaction(ST_accountDatabase_t* account_data,ST_transDatabase_t* trans_data);


#endif // SERVER_H_