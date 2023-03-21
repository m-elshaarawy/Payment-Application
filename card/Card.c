

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


