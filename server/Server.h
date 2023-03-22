

#ifndef SERVER_H_
#define SERVER_H_

#include "../terminal/Terminal.h"

/* data typs and structs */

typedef struct {

    char server_PAN[17];
    EN_accountState_t account_state;
    unsigned int funds;

}ST_accountDatabase_t;


typedef struct {
    
    ST_cardData_t card_data;
    ST_terminalData_t term_data;

}ST_transactionData_t;

typedef struct {
    
    unsigned int trans_number;
    ST_transactionData_t trans_data;

}ST_transDatabase_t;

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


/* Function prototypes */

EN_transactionState_t receiveTransactionData(ST_transactionData_t* transData);
EN_accountState_t isValidAccount();
EN_transactionState_t isAmountAvailable();
EN_transactionState_t saveTransaction();


#endif // SERVER_H_