
#include  "../terminal/Terminal.h"


EN_terminalError_t getTransactionData(ST_terminalData_t* data){

char i=0;
char date[6];
printf("Enter transaction amount : ");
// get transaction amount
scanf("%d",&(data->transAmount));

printf("Enter transaction date  [mm/yy] : ");
// get transDate
scanf("%d",date);
 // check the validity of the date
 if( date[5]!='\0' || date[2]!='/'  || (((date[0]-'0')*10+(date[1]-'0'))>12) || (((date[3]-'0')*10+(date[4]-'0'))>99) ){

 return INVALID_DATA;

 }
// save valid date
for(i=0;i<6;i++){
    data->transDate[i]=date[i];
}

return DONE;
}

EN_terminalError_t isCardExpired(ST_terminalData_t *data , ST_cardData_t card){

         // check for yy
if(((card.ExpDate[3]-'0')+(card.ExpDate[4]-'0'))<((data->transDate[3]-'0')+(data->transDate[4]-'0'))){

 return EXPIRED_CARD;
        // check for mm
}else if(((card.ExpDate[3]-'0')+(card.ExpDate[4]-'0'))==((data->transDate[3]-'0')+(data->transDate[4]-'0'))){

  if(((card.ExpDate[0]-'0')+(card.ExpDate[1]-'0'))<((data->transDate[0]-'0')+(data->transDate[1]-'0'))){

  return EXPIRED_CARD;
  }

}

return DONE;
}