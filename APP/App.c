
#include "../APP/App.h"

void appStart(void){
   
   
    ST_cardData_t card={0};
    ST_terminalData_t termData={0};
    ST_transactionData_t transData={0};
    
   // get card holder name and check validity 
   if( getCardHolderName(&card)==INVALID_NAME){
    printf(" Declined Invaled Name \n");
    return;
   }

    // get card Expiry dat and check validity 
   if( getCardExpiryDate(&card)==INVALID_DATE){
    printf("Declined Invaled Expiry date \n");
    return;
   }else{
    // get transaction date and check validity 
    if(getTransactionDate(&termData)==INVALID_DATA){
        printf("Declined Invalid transaction date \n");
     return; 
    }else{
        if(isCardExpired(&termData , card)==EXPIRED_CARD){
           printf("Declined Expired card \n");
         return;    
        }     
    }
   }

   // get card PAN and check validity 
   if (getCardPAN(&card)==INVALID_PAN) {
    printf("Declined Invaled PAN \n");
    return;
   }
   // get max transaction amount and check validity 
   if(setMaxAmount(&termData)==INVALID_DATA){
        printf("Declined Invaled Max transaction amount \n");
    return;
   }
    
    // get transaction amount and check validity 
   if(getTransactionAmount(&termData)==INVALID_DATA){
      printf("Declined Invaled  transaction amount \n");
    return;
   }else{
       if(isBelowMaxAmount(&termData)==EXCEED_LIMIT){
          printf("Declined Amount  Exceeding Limit \n");
        return;
       }
   } 
    
  // server receiving data 
   receiveTransactionData(&transData,&card,&termData);

   // check accounts
   if(isValidAccount(&transData,&accountDatabase)==INVALID_ACCOUNT){
       printf("Declined Invailed Account \n");
     return;    
   }

  if(isAmountAvailable(&transData,&accountDatabase)==UNAVAILABLE){
       printf("Declined Insuffecient funds \n");
     return;      
  }

  if(saveTransaction(&accountDatabase ,&transDatabase ,&transData )==VALID_TRANS){
       
       printf(" Transaction Complete \n");
  }




}