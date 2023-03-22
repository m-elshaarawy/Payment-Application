
#include "Server.h"

static unsigned int trans_count=0; // hold transaction number  

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