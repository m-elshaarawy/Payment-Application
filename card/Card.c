

#include "../card/Card.h"



EN_cardError_t getCardHolderName(ST_cardData_t* card){
 char data[25];
 char counter=0 , i=0; 
 printf("Enter name as on card [<=24 (char+' ')]: ");

 gets(data);

for(i=0;data[i];i++){
//checking for lowercase chars
if( data[i] >= 'a' && data[i] <= 'z'){

return INVALID_NAME;

  }
counter++;
}

// checking for overflow 
if(counter>24){
return INVALID_NAME; 
}

// copying  valid name 
for(i=0;i<=counter;i++){
card->name[i]=data[i];
}

return VALID;
}



EN_cardError_t getCardExpiryDate(ST_cardData_t* card){

 char data[6];
 char i=0;
 printf("Enter expiry date [mm/yy] : ");
 
 gets(data);
 
 // check the validity of the date
 if( data[5]!='\0' || data[2]!='/'  || (((data[0]-'0')*10+(data[1]-'0'))>12) || (((data[3]-'0')*10+(data[4]-'0'))>99) ){

 return INVALID_DATE;

 }

 // copy valid date
 for(i=0;i<6;i++){

 card->ExpDate[i]=data[i];

 }

 return VALID;
}


