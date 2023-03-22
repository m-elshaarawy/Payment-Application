
#include "Server.h"

static unsigned int trans_count=0; // hold transaction number  
char index=0; // store index of valid accounts

// small account database    contain  PAN , account_state , funds 
static ST_accountDatabase_t accountDatabase[6]={
    {"AHMED MOHAMED","0676362769002729", ACTIVE  ,50000},
    {"ALI ALI","7012292292334563", ACTIVE  ,40000},
    {"MOHAMED ELSHAARAWY","3899713628095627", BLOCKED ,0},
    {"HYSAM KAMEL","9804196396743949", ACTIVE  ,100000},
    {"kAMAL ALI","0877553266672886", ACTIVE  ,10000},
    {"SARA AHMED","3660604046475564", BLOCKED ,0}
    };

// transactions database 
static ST_transDatabase_t transDatabase[200]={0};


EN_transactionState_t receiveTransactionData(ST_transactionData_t* transData,ST_cardData_t* cardData,ST_terminalData_t* termData){

char i=0;
// receiving card name 
for(i=0;(cardData->name[i]);i++){
 transData->card_data.name[i]=cardData->name[i];
 }
transData->card_data.name[i]='\0';

// receiving card PAN
for(i=0;i<17;i++){
transData->card_data.PAN[i]=cardData->PAN[i];
 }

// receiving card expiry date
 for(i=0;i<6;i++){
transData->card_data.ExpDate[i]=cardData->ExpDate[i];
 }

// reciving max transaction amount
transData->term_data.maxTransAmount=termData->maxTransAmount;

// reciving transaction amount
transData->term_data.transAmount=termData->transAmount;

// receiving transaction date
 for(i=0;i<6;i++){
transData->term_data.transDate[i]=termData->transDate[i];
 }


  return VALID_TRANS;  
}


EN_accountState_t isValidAccount(ST_transactionData_t* transData,ST_accountDatabase_t* accountData){
  
  char i=0;
  for(i=0;i<6;i++){
   
   // check account name 
  if(strcmp(transData->card_data.name, accountData[i].accountName)==0){

   // check account PAN
    if(strcmp(transData->card_data.PAN, accountData[i].server_PAN)==0){

       // ckeck account state
          if((accountData[i].account_state)==ACTIVE){
             index=i; // store account index
           return ACTIVE;
          }else{
            return INVALID_ACCOUNT;
          }

    }

  }
    
  }
  
  return INVALID_ACCOUNT;
}


EN_transactionState_t isAmountAvailable(ST_transactionData_t* transData,ST_accountDatabase_t* accountData){

    // check for funds amount
   if( transData->term_data.transAmount <= accountData[index].funds ){

    return AVAILABLE;
   }

   return UNAVAILABLE;
}


EN_transactionState_t saveTransaction(ST_accountDatabase_t* accountData ,ST_transDatabase_t* trans_database , ST_transactionData_t* transData ){

    // update account balance
   accountData[index].funds = accountData[index].funds - transData->term_data.transAmount ;
   
   // increasing transaction number 
   trans_database[trans_count].trans_number=(trans_count+1);
   
   // save transaction data
   trans_database[trans_count].trans_data.term_data = transData->term_data;
   trans_database[trans_count].trans_data.card_data = transData->card_data;

    trans_count++;

    return VALID_TRANS;
}